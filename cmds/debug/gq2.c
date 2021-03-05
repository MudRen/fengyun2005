// THIS COMMAND IS DESTRUCTIVE!!!
/*
it generates three files in /log
LOC NPC and OBJ

LOC is being renamed to dynamic_location
NPC and OBJ are being used by questing
*/
#include <combat.h>
#include <ansi.h>
#define SYNTAX	"指令格式：gq <dir>\n"
int do_one_object(object obj,int pri);
string scores(object ob);
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int i;
	string direc,*dir, roomname;
	string status;
	object room;
        //if(!me->query("env/yesiknow")) 
        return notify_fail("这个指令已经被废除了！\n");
	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");
	if( !arg ) return notify_fail(SYNTAX);
	if( sscanf(arg, "%s", direc)!=1 )
		return notify_fail(SYNTAX);
	seteuid(getuid());
	dir = get_dir(arg+"/");
        for(i=0; i<sizeof(dir); i++) {
	if( sscanf(dir[i],"%s.c", roomname) != 1) continue;
	if( room = find_object(arg+"/"+roomname+".c"))
			destruct(room);	
	room = load_object(arg+"/"+roomname+".c");
	write("working on "+roomname+"\n");
	if(do_one_object(room,0))
        log_file("LIST",sprintf("\n"));
	}
// now let's setup in npc dir to take care of those left over npcs
	log_file("LIST",sprintf("HIDDEN NPCS\n"));
	dir = get_dir(arg+"/npc/");	
        for(i=0; i<sizeof(dir); i++) {
        if( sscanf(dir[i],"%s.c", roomname) != 1) continue;
        if( room = find_object(arg+"/npc/"+roomname+".c"))
                        destruct(room);
        room = load_object(arg+"/npc/"+roomname+".c");
        write("working on "+roomname+"\n");
        if(do_one_object(room,1))
        log_file("LIST",sprintf("\n"));
        }
// now let's setup in obj dir to take care of those left over objs
        log_file("LIST",sprintf("HIDDEN OBJS\n"));
        dir = get_dir(arg+"/obj/");
        for(i=0; i<sizeof(dir); i++) {
        if( sscanf(dir[i],"%s.c", roomname) != 1) continue;
        if( room = find_object(arg+"/obj/"+roomname+".c"))
                        destruct(room);
        room = load_object(arg+"/obj/"+roomname+".c");
        write("working on "+roomname+"\n");
        if(do_one_object(room,1))
        log_file("LIST",sprintf("\n"));
        }
	return 1;
}

int do_one_object(object room,int pri)
{
int i, att,def;
string name, short;
string skill_type,parry_type;
int attack_points,parry_points,dodge_points;
object *inv, weapon;
//let's remove its' file
	rm(base_name(room)+".c");
	if(room->query("coor"))
	log_file("LOC",sprintf("%s\n",base_name(room)+".c"));
	inv = all_inventory(room);	
	name= room->query("name");
	if(!name) short = room->query("short");
	else short = name;
	if(pri && !sizeof(inv)) log_file("LIST",sprintf("\n %s\n",short));
	if( sizeof(inv) )
	{
        log_file("LIST",sprintf("\n %s ：",short));
        for(i=0; i<sizeof(inv); i++) {
                        log_file("LIST",sprintf("%s",inv[i]->query("name")));
			if(inv[i]->is_character()) log_file("LIST",sprintf("%s",scores(inv[i])));	
			log_file("LIST",sprintf("，"));
			if(inv[i]->is_character()) log_file("NPC",sprintf("%s\n",inv[i]->query("name")));
			else
			if("布衣" != inv[i]->query("name") &&
			!inv[i]->query("no_shown") && !inv[i]->query("no_get")
			&& !inv[i]->query("no_drop"))
			log_file("OBJ",sprintf("%s%s\n",inv[i]->query("unit"),
inv[i]->query("name")));

        }
        for(i=0; i<sizeof(inv); i++) {
			do_one_object(inv[i],0);
	}
	return 1;
	}
	return 0;

}
 string scores(object room)
{
int i, att,def;
string name, short;
string skill_type,parry_type;
int attack_points,parry_points,dodge_points;
object *inv, weapon;
        if(room->is_character())
        {
        attack_points = COMBAT_D->skill_power(room, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(room, SKILL_USAGE_PARRY);
        dodge_points = COMBAT_D->skill_power(room, SKILL_USAGE_DODGE);
        return sprintf("（%d，%d）",
                attack_points + 1,
                (dodge_points/2 + (weapon? parry_points: (parry_points/2))) + 1);
	}
	return " ";
}
