
inherit ITEM;

void create()
{
	set_name("书桌", ({ "desk", "红木书桌" , "书桌", "桌"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("prep", "on");
		set("long", "一张红木书桌\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

