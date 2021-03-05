#include <ansi.h>
inherit NPC;
int clean_trash();
int	pickup();
int randommove();

void create()
{
//      int i,amun;
        string *order = ({"张", "王", "李", "赵", "孙", "徐", "郑", "周", "吴",
"蒋", "沈", "杨", "苗", "尹", "金", "魏", "陶" });
	string *orderr = ({"定国", "安邦", "抚民", "守疆", "平安",
"国泰", "民安", "丰谷"});
        set_name( order[random(17)] + orderr[random(8)], ({ "shou", "chang" }) );
		set("title", "收藏家");
		set("gender", "男性" );
		set("age", random(20)+20);
		set("env/wimpy",90);
        set("vendetta_mark", "authority");
		set("str", 30);
		set("long",HIR"他以清理风云的垃圾为生。朝廷官派，你最好不要招惹他。
杀了他会导致所有官兵的追杀。\n"NOR);
        set("chat_chance", 80);
        set("chat_msg", ({
                (: pickup :),
                (: randommove :),	
        }) );

		set("attitude", "friendly");
		set("combat_exp", 1000);
		setup();
		carry_object("/obj/armor/cloth")->wear();
}


int pickup (){
	
// clean up all trash
	object room , *inv, intem;
	int i;
	mapping my_armor;
	string *my_armor_name;
	string armor_type;
	
	room = environment(this_object());
	if(room)
	{
		inv = all_inventory(room);
        	for(i=0; i<sizeof(inv); i++) {
			if( userp( inv[i]) ) 
			{
				if ( !random(5))
				set_leader(inv[i]);
				continue;
			}
			if( inv[i]->query("no_shown")) continue;
			if( inv[i]->query("no_get")) continue;
			if( inv[i]->is_character()) continue;
			if( inv[i]->is_corpse()) continue;
			command("get "+ inv[i]->query("id"));
// 嘿嘿，let's make it fun.... by Silencer@fy4.
			if (inv[i]->query("armor_prop")) {
				armor_type = inv[i]->query("armor_type");
				my_armor = query_temp("armor");	
				if (!my_armor) {
					command("wear "+inv[i]->query("id"));
					continue;
				}
				my_armor_name = keys(my_armor);
				if (member_array(armor_type,my_armor_name)== -1)
					command("wear "+inv[i]->query("id"));
					else if (my_armor[armor_type]->query("value") < inv[i]->query("value")) {
						intem = my_armor[armor_type];
						command("remove "+my_armor[armor_type]->query("id"));
						destruct(intem);
						command("wear "+inv[i]->query("id"));
						continue;
					} else				
						destruct(inv[i]);
			} else if (inv[i]->query("weapon_prop") && !this_object()->query_temp("weapon"))
					command("wield all");
			else
				destruct(inv[i]);
			
		}
	}	
}

int randommove()
{
        mapping exits;
        string *dirs;
				string thisdir;
        
        if (query_temp("random_move")>= 160 && query("startroom") && !query("no_return")) {
					if (return_home(query("startroom")))
						delete_temp("random_move");
					return 1;
				}
        
        if( !mapp(exits = environment()->query("exits")) ) 
				{
					destruct(this_object());
					return 0;
				}
        dirs = keys(exits);
				thisdir = dirs[random(sizeof(dirs))];
				this_object()->set("last_dir",thisdir);
        command("go " + thisdir);
        add_temp("random_move",1);
}


int clean_trash()
{
	mapping exits;
	string *dirs;
	string last_dir;
	if( last_dir = this_object()->query("last_dir"))
	{
        	if( !mapp(exits = environment()->query("exits")) ) {
			destruct(this_object());
			return 0;
		}
        	dirs = keys(exits);
		if( member_array(last_dir, dirs) != -1)		{
			if( random(2) )
				command("go "+ last_dir);
			else
				randommove();
		}		
		else
			randommove();
	}else
		randommove();
}
