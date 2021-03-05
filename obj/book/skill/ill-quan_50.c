inherit ITEM;
void create()
{
	set_name("墙", ({ "wall" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long","一面雪白的墙壁，上面有许多各种姿势的人形。\n");
		set("no_shown",1);
                set("material", "stone");
		set("no_get",1);
		set("skill", ([
			"name": 	"ill-quan",	
			"exp_required":	10000,		
			"sen_cost":	10,	
			"difficulty":	20,	
			"max_skill":	49		
		]) );
	}
    	::init_item();
}
void init()
{
  	add_action("do_study","study");
}


int do_study(string arg)
{
    	string book;
    	string sena;
    	if(!arg || sscanf(arg, "%s %d", book, sena)!=2 ) return 0;
    	if (book == "wall" || book  == "墙")
    	if (!this_player()->query_temp("mark/arraying"))
      	{ 
        	tell_object(this_player(),"你必须结合少女的招式才能领会病维摩拳。\n");
        	return 1;
      	}
    	return 0;
}