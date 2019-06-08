//
//  openedHash.cpp
//  ATD_DICTIONARY
//
//  Created by Тимур Гарипов on 27/03/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include "openedHash.hpp"
#include "constants.h"

int openedHash:: dictionary:: space = 0;
const int openedHash:: dictionary:: B = N % 10; // делим на классы
openedHash:: elem openedHash:: dictionary:: arr[SIZE];

