/* J2735 BSM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_BSM_H__
#define __J2735_BSM_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BasicSafetyMessage {
    BSMcoreData coreData;
    BOOL partII_option;
    PartIIcontentList partII;
    BOOL regional_option;
    Reg_BasicSafetyMessageList regional;
} BasicSafetyMessage;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_BSM_H__ */
