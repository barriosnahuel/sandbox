//  Created by: Nahuel Barrios <barrios.nahuel@gmail.com>.
//  On: 1/19/13 at 3:47 PMhs.

var service = service || {}

service.convert = function (from, fromRate, currencies, toRateIndex) {
    var converted
    if (from.length <= 0 || fromRate <= 0.0) {
        converted = ""
    } else {
        converted = currencies.getRate(toRateIndex) * (parseFloat(from) / fromRate)
    }

    return converted
}
