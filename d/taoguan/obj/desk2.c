
inherit ITEM;

void create()
{
	set_name("香炉", ({ "香炉"}) );
	set_weight(500);
	set_max_encumbrance(20000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("prep", "under");
		set("long", "一尊终日里青烟袅袅的香炉，其下可以藏起一些东西。\n");
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

