
// written by suu, if find any bugs, please report. *bow
#include <ansi.h>
inherit NPC;

mapping *way;
object carriage;
mapping *read_table(string);
int arrive_guanwai();

void create()
{
    	object ob;
    	set_name("马车夫", ({ "chefu" }) );
    	set("gender", "男性" );
    	set("long","一个一身白衣的马车夫。\n");
    	set("age", 25);
    	set("combat_exp", 100000);
    	set("attitude", "friendly");
    	set("force",500);
    	set("max_force",500);
    	set("force_factor",40);
    	set_skill("blade",50);
    	set_skill("shortsong-blade",50);
    	set_skill("force",40);
    	set_skill("parry",150);
    	set_skill("dodge",150);
    	map_skill("blade","shortsong-blade");
    	map_skill("parry","shortsong-blade");
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/blade")->wield();
    	carry_object("/obj/example/wineskin");
}

void go()
{
    	int i,j;
    	string *cmds;
    	remove_call_out("go");
    	for(i=0;i<sizeof(way);i++)
    	{
        	if (base_name(environment()) != way[i]["room_file"]) continue;
        	cmds=explode(way[i]["cmd_table"],";");
        	break;
    	}
    
/*    	if (i>=sizeof(way))
    	{   
        	random_move();
        	carriage->move(environment());
        	message_vision(YEL"黑漆大马车隆隆驶了过来。\n"NOR,this_object());
        	call_out("go",5);
        	return;
    	}*/
    	
    	for(j=0;j<sizeof(cmds);j++)
        	command(cmds[j]);
    	carriage->move(environment());
    	message_vision(YEL"黑漆大马车隆隆驶了过来。\n"NOR,this_object());
    	if (way[i]["delay_time"]<0)
    	{
        	arrive_guanwai();
        	return;
    	}
    	call_out("go",way[i]["delay_time"]);
    	return;
}	



void get_quest(string file)
{   
    	way=read_table(file);
}

mapping *read_table(string file)
{
    	string *line, *field, *format;
    	mapping *data;
    	int i, rn, fn;

    	line = explode(read_file(file), "\n");
    	data = ({});
    	for(i=0; i<sizeof(line); i++) {
        	if( line[i]=="" || line[i][0]=='#' ) continue;
        	if( !pointerp(field) ) {
            		field = explode( line[i], ":" );
            		continue;
        	}
        	if( !pointerp(format) ) {
            		format = explode( line[i], ":" );
            		continue;
        	}
        	break;
    	}

    	for( rn = 0, fn = 0; i<sizeof(line); i++) {
        	if( line[i]=="" || line[i][0]=='#' ) continue;
        	if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
        	sscanf( line[i], format[fn], data[rn][field[fn]] );
        	fn = (++fn) % sizeof(field);
        	if( !fn ) ++rn;
    	}
    	return data;
}

void set_carriage(object mache)
	{carriage=mache; }

object query_carriage()
	{ return carriage; }

int arrive_guanwai()
{
	object *inv;
	int i;
	inv=all_inventory(carriage);
    	for(i=0;i<sizeof(inv);i++)
        if (userp(inv[i]))
        {
			inv[i]->move(environment(this_object()));			
			message_vision(WHT"$N从马车上走了下来。"NOR,inv[i]);
        }else
		{
			destruct(inv[i]);
		}
	
	message_vision(WHT"$n驾着$N又向边城方向驰去。\n"NOR,carriage,this_object());
	destruct(carriage);
	destruct(this_object());
	return 1;
}



void die()
{
    
    	object *inv;
    	int i;
    	if (objectp(carriage))
    	{
		 carriage->delete("no_reset"); //allow system to clean it up
        	 inv=all_inventory(carriage);
         	for(i=0;i<sizeof(inv);i++)
         	{
			 if (userp(inv[i]))  {
                    		tell_object(inv[i], RED "车夫命在旦夕，快逃生去吧！ \n"NOR);
				message_vision("$N慌忙向马车外逃去。\n",inv[i]);
				inv[i]->move(environment(carriage));
				message_vision("$N逃出了马车。\n",inv[i]);
                	}  else
                    		destruct(inv[i]);
        	}
    	}
    	::die();
}


void go_now()
{
    	call_out("go",10);
}
