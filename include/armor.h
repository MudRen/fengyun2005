// armor.h

/*		fengyun 4.1 护具重定义	--2/20/2003 by Silencer

＊＊＊　注明普通使用者不得有任何除装饰外的属性（无防护力等），除非解密需要。
＊＊＊	所有有特殊作用的防具建议放在／ｏｂｊ／ａｒｍｏｒ中有利维护。
＊＊＊　施法指由Ａｄｄ＿ａｃｔｉｏｎ来ｐｅｒｆｏｒｍ一个东西。
＊＊＊　防具另有／ｓｅｘ／ｅｘｐ／ｓｔｒ／ａｇｉ的要求定义在／ｃｍｄｓ／ｗｅａｒ中。
＊＊＊	加属性／特殊效用／施法等的护具建议讨论后放入。
＊＊＊　０－１０－３０的含义是，０－１０的为一般物品，１０－３０为特殊物品。
	
	HEAD: 	头巾、头盔，防护力(0-30-50)，＋parry(0-5-20)，特定效用PARRY_HIT。+per 0-5
	BOOTS:	防护力(0-5-20)，＋dodge(0-10-30)，特定效用DODGE_HIT。
	CLOTH: 	轻而低防护力，重而高防护力。／属性／Resistance／施法／
		(0-50-200) + parry/dodge/force(0-0-10)等。		
	SHIELD: 防护力，(0-20-50) 可以用来ＢＬＯＣＫ，需要相应技艺来发挥作用。
	FINGER：戒指，属性／施法／		+3per 常见
	SURCOAT:披风，防护力，(0-10) 普通使用。
	
	NECK：	佛珠，普通使用。
	WRIST：	丝巾，普通使用。手镯 per (1-3)
	WAIST：	腰带，普通使用。
	HAND：	手套，普通使用。
	
	MASK: 	隐藏身份专用，不具有任何其他属性。
	ARMOR: --- 舍弃不用
*/

#ifndef	__ARMOR__
#define	__ARMOR__

// Standard	inheritable	armor objects.
#define	HEAD		"/std/armor/head"
#define	MASK		"/std/armor/mask"
#define	NECK		"/std/armor/neck"
#define	CLOTH		"/std/armor/cloth"
#define	ARMOR		"/std/armor/armor"
#define	SURCOAT		"/std/armor/surcoat"
#define	WAIST		"/std/armor/waist"
#define	WRISTS		"/std/armor/wrists"
#define	SHIELD		"/std/armor/shield"
#define	FINGER		"/std/armor/finger"
#define	HANDS		"/std/armor/hands"
#define	BOOTS		"/std/armor/boots"

// Standard	armor types
#define	TYPE_HEAD		"head"
#define	TYPE_MASK		"mask"
#define	TYPE_NECK		"neck"
#define	TYPE_CLOTH		"cloth"
#define	TYPE_ARMOR		"armor"
#define	TYPE_SURCOAT		"surcoat"
#define	TYPE_WAIST		"waist"
#define	TYPE_WRISTS		"wrists"
#define	TYPE_SHIELD		"shield"
#define	TYPE_FINGER		"finger"
#define	TYPE_HANDS		"hands"
#define	TYPE_BOOTS		"boots"

// Standard	armor desc
#define	WORN_HEAD		"头戴"
#define WORN_MASK		"脸罩"
#define	WORN_NECK		"颈挂"
#define	WORN_CLOTH		"身穿"
#define	WORN_ARMOR		"身穿"
#define	WORN_SURCOAT		"身披"
#define	WORN_WAIST		"腰带"
#define	WORN_WRISTS		"腕罩"
#define	WORN_SHIELD		"手执"
#define	WORN_FINGER		"指戴"
#define	WORN_HANDS		"手戴"
#define	WORN_BOOTS		"脚穿"

#endif
