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
				set("no_split",1);
                set("long", "\n　谕诸\n\n　灵\n　不\n");
                set("value", 1);
        }
}

/*
字 谕诸众 ， 传
令 杜君山 速 至
幽 灵山庄 行 事
， 不得怠 误 ！
*/