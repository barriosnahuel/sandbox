import QtQuick 2.0
import QtQuick.XmlListModel 2.0
import Ubuntu.Components 0.1

import Ubuntu.Components.ListItems 0.1
import Ubuntu.Components.Popups 0.1

import "../js-view/currencyConverter.js" as Behavior
import "../js/service/currencyService.js" as Currency

Rectangle {
    id: root
    width: units.gu(60)
    height: units.gu(40)
    color: "lightgray"

    property real margins: units.gu(2)
    property real buttonWidth: units.gu(9)

    Label {
        id: title
        ItemStyle.class: "title"
        text: i18n.tr("Currency Converter")
        height: contentHeight + root.margins
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
    }
    ListModel {
        id: currencies
        ListElement {
            currency: "EUR"
            rate: 1.0
        }

        function getCurrency(idx) {
            return (idx >= 0 && idx < count) ? get(idx).currency : ""
        }

        function getRate(idx) {
            return (idx >= 0 && idx < count) ? get(idx).rate : 0.0
        }
    }
    XmlListModel {
        id: ratesFetcher
        source: "http://www.ecb.int/stats/eurofxref/eurofxref-daily.xml"
        namespaceDeclarations: "declare namespace gesmes='http://www.gesmes.org/xml/2002-08-01';"
                               + "declare default element namespace 'http://www.ecb.int/vocabulary/2002-08-01/eurofxref';"
        query: "/gesmes:Envelope/Cube/Cube/Cube"

        onStatusChanged: Behavior.xmlListModel.onStatusChanged(currencies,
                                                               ratesFetcher)

        XmlRole {
            name: "currency"
            query: "@currency/string()"
        }
        XmlRole {
            name: "rate"
            query: "@rate/string()"
        }
    }

    ActivityIndicator {
        anchors.right: parent.right
        running: ratesFetcher.status === XmlListModel.Loading
    }

    Component {
        id: currencySelector
        Popover {
            Column {
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }
                height: pageLayout.height
                Header {
                    id: header
                    text: i18n.tr("Select currency")
                }
                ListView {
                    clip: true
                    width: parent.width
                    height: parent.height - header.height
                    model: currencies
                    delegate: Standard {
                        text: currency
                        onClicked: {
                            caller.currencyIndex = index
                            caller.input.update
                            hide()
                        }
                    }
                }
            }
        }
    }

    Column {
        id: pageLayout

        anchors {
            fill: parent
            margins: root.margins
            topMargin: title.height
        }
        spacing: units.gu(1)

        Row {
            spacing: units.gu(1)

            Button {
                id: selectorFrom
                property int currencyIndex: 0
                property TextField input: inputFrom
                text: currencies.getCurrency(currencyIndex)
                onClicked: PopupUtils.open(currencySelector, selectorFrom)
            }

            TextField {
                id: inputFrom
                errorHighlight: false
                validator: DoubleValidator {
                    notation: DoubleValidator.StandardNotation
                }
                width: pageLayout.width - 2 * root.margins - root.buttonWidth
                height: units.gu(4)
                font.pixelSize: FontUtils.sizeToPixels("medium")
                text: '0.0'
                onTextChanged: Behavior.textField.onTextChanged(
                                   Currency.service, inputFrom, inputTo,
                                   currencies, selectorFrom, selectorTo)

                function update() {
                    text = Currency.service.convert(
                                inputTo.text,
                                currencies.getRate(selectorTo.currencyIndex),
                                currencies, selectorFrom.currencyIndex)
                }
            }
        }

        Row {
            spacing: units.gu(1)
            Button {
                id: selectorTo
                property int currencyIndex: 1
                property TextField input: inputTo
                text: currencies.getCurrency(currencyIndex)
                onClicked: PopupUtils.open(currencySelector, selectorTo)
            }

            TextField {
                id: inputTo
                errorHighlight: false
                validator: DoubleValidator {
                    notation: DoubleValidator.StandardNotation
                }
                width: pageLayout.width - 2 * root.margins - root.buttonWidth
                height: units.gu(4)
                font.pixelSize: FontUtils.sizeToPixels("medium")
                text: '0.0'
                onTextChanged: Behavior.textField.onTextChanged(
                                   Currency.service, inputTo, inputFrom,
                                   currencies, selectorTo, selectorFrom)

                function update() {
                    text = Currency.service.convert(
                                inputFrom.text,
                                currencies.getRate(selectorFrom.currencyIndex),
                                currencies, selectorTo.currencyIndex)
                }
            }
        }

        Button {
            text: i18n.tr("Clear")
            width: units.gu(12)
            onClicked: {
                inputTo.text = '0.0'
                inputFrom.text = '0.0'
            }
        }
    }
}
