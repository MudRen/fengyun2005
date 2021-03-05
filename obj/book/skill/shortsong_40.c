// An example book

inherit ITEM;

void create()
{
	set_name("短歌刀法秘笈" , ({ "shortsong-blade" }) );
        set_weight(600);
        set("lore",1);
        set("unit", "本");
        set("long", "这是一本介绍短歌刀法的武功秘笈。\n");
        set("value", 0);
        set("skill", ([
                "name":                 "shortsong-blade",      
                "exp_required": 200000,       
                "sen_cost":             1,
                "difficulty":   1,  
                "max_skill":    40,
                "literate":	"qidaoforce",
                "liter_level":	150,      
        ]) );
}
 
void init(){

	if(this_player() != environment()) {
		add_action("do_get", "get");
	}
}


int flower_gone(){
	message_vision("一阵风吹过，书页竟然片片散落飘逝而去。\n", this_object());
	destruct(this_object());
	return 1;
}

int do_get(string arg) {
	if (arg == query("id")) 
		call_out("flower_gone",600);
	return 0;
}