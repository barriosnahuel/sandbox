//  Created by: Nahuel Barrios <barrios.nahuel@gmail.com>.
//  On: 1/19/13 at 3:08 PMhs.

var xmlListModel = xmlListModel || {

}

var textField = textField || {

}

xmlListModel.onStatusChanged = function (currencies, xmlListModel) {

    if (xmlListModel.status === XmlListModel.Ready) {

        for (var i = 0; i < xmlListModel.count; i++) {
            currencies.append({
                currency:xmlListModel.get(i).currency,
                rate:parseFloat(xmlListModel.get(i).rate)
            })
        }
    }
}


textField.onTextChanged = function (currencyService, input, output, currencies, currenciesSelectorFrom, currenciesSelectorTo) {
    if (input.activeFocus) {

        output.text = currencyService.convert(
            input.text,
            currencies.getRate(currenciesSelectorFrom.currencyIndex), currencies,
            currenciesSelectorTo.currencyIndex)
    }
}
