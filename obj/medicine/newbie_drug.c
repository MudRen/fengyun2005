inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("金创药",({"drug"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","俗话说，不学打人，先学挨打。在江湖上行走，要想做个大侠或者魔头，免不了要
磕磕碰碰地受点伤，用ｈｐ命令看一下自己，（如果你刚从灵池过来，肯定有点小
伤）。有的伤可以用运气（ｅｘｅｒｔ）治疗，如果是外伤（百分比受损），则需
要服用药物。这是一盒上好的金创药，可以治疗气血的外伤，一次治疗１００点。
命令格式为ｕｓｅ　ｄｒｕｇ，如果你的心神或者精力受到损伤，可以到风云东地
巷大胖子那里买几盒狗皮膏药，或者到城里西南部的枫叶泉去洗个澡儿。\n");
	    set("unit","盒");
	    set("base_unit","包");
	    set("base_weight",30);
	    set("material","herb");
	    set("no_drop", 1);

		set("desc_ext","治疗外伤(use drug)");	// annie. 
	    
	    set("usage_type","pill");
	    set("heal_type","kee/100");
	    set("type","cure");
	    set("base_value",0);
	    set("effect",100);
	    set("field","kee");
	    set("volumn",100);
	}
	set_amount(100);
}

