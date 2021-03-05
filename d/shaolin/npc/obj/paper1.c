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
                set("long", "\n字\n令\n幽\n，\n");
				set("no_split",1);
                set("value", 1);
        }
}

/*

字谕诸众，传
令杜君山速至
幽灵山庄行事
，不得怠误！
*/