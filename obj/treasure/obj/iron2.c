inherit ITEM;
void create()
{
        set_name("陨石碎片", ({ "meteor shard" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 0);
				set("no_clean_up",1);
				set("no_reset",1);
                set("no_stack", 1);

							set("weapon_material",1);
			set("material_level",68);
			set("desc_ext","祭炼武器(68)");

		}
    ::init_item();
}


int init_spawn()
{
	object room;
	room = find_object("/d/palace/lighthole3");
	if (!room)
		room = load_object("/d/palace/lighthole3");
	if (!room)
		return 0;

	move(room);
	return 1;
}


/*
void remove_all_killer()	// 因为destruct函式中呼叫了这个func，而item没有原定义，因此可以利用来解除protect防止错误。 annie.
{
	if (environment())
	SPAWN_D->restart_spawn(query("spawn_num"),0);
	return;
}

*/



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

