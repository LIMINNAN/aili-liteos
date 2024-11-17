/**
 * @file MvvmModel.h
 * @author Lisaro (lli747723@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-09-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MVVM_MODEL_H
#define MVVM_MODEL_H

#include "lv_eventkit.h"

class MvvmModel {
  public:
    virtual MvvmModel() = default;
    virtual ~MvvmModel() = default;
};

#endif // MVVM_MODEL_H