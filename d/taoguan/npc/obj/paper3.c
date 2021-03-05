// ; annie 07.2003
// dancing_faery@hotmail.com
// 
inherit ITEM;

void create()
{
        set_name("小纸片", ({ "paper"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "\n　　　众\n\n　　山庄\n　　得\n");
				set("no_split",1);
                set("value", 1);
        }
}



/*
字 谕诸众 ， 传
令 杜君山 速 至
幽 灵山庄 行 事
， 不得怠 误 ！
*/