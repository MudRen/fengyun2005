// this npc will duplicate anyone who he/she lost his fight to....
#include <ansi.h>
#define CHAMPION_FILE "/obj/npc/champion.o"

inherit NPC;
void loadall(object me);
void changeshape(object winner);
int brag();

void create()
{
	string info,name,id,file;
    set_name( "盟主" , ({ "numberone" }) );
    set("chat_chance", 1);
    set("chat_msg", ({
//          (: brag :),
        }) );
	setup();
	info = read_file(CHAMPION_FILE);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
		restore_object(file);
        set_name( name , ({ id }) );
        delete("env");
        set("attitude", "aggressive");
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object());
        set("title", HIR "天下第一人"NOR);
	}
	setup();	
		
}

void lose_enemy(object winner)
{
	call_out("changeshape",2,winner);
	return;
}

void win_enemy(object loser)
{
	CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "莹火之光，也敢与日月争辉？%s你还是去多练几年吧! ! \n",
        loser->name(1)));
	
	return;		
}
void changeshape( object winner)
{
	string winner_file;
	string name,id;
	int force;
	
	if (query("change_time")+ 4 > time())	// 每4秒钟只能换一次手。
		return;
	
	if(!stringp(winner_file = winner->query_save_file()))
		return;
       
    CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s勇夺『天下第一人』! ! ! \n",
        winner->name(1)));
	seteuid(ROOT_UID);
	write_file(CHAMPION_FILE,sprintf("%s %s %s",
	winner_file,winner->query("id"),winner->query("name")),1);
	seteuid(getuid());
	restore_object(winner_file);
	name = winner->query("name");
	id = winner->query("id");
	set_name( name , ({ id }) );
	delete("env");
	delete("marry");
	
	force = query_skill("force");
	force = force/3;
	set("force_factor",force);
		
	set("attitude", "aggressive");
	reset_action();
	delete_temp("already_loaded");
	loadall(this_object());	
    set("title", HIR "天下第一人"NOR);   
    set_name( name , ({ "mengzhu "+ id }) );
    setup();
    set("change_time",time());
    return ;
}

void loadall(object me)
{
    int MAX = 3;
    string name,id, *created;
    int i,j;
    object thing, *inv,cloth;
	
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
    	destruct(inv[i]);

    id = me->query("id");
    created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
    for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
    if( sscanf(created[j], "%s.c", name) == 1 )
    {
		thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id +
 		"/" + name + ".c");
        if (objectp(thing)){
	        if(thing->move(me)) 
			{
				thing->restore();
				thing->wield();
				thing->wear();
			} else
				destruct(thing);
		}
    }
    cloth = new("/obj/armor/cloth");
    cloth->move(me);
    cloth->wear();
	me->reset_action();
	me->remove_all_enemy();
    me->set_temp("already_loaded",1);
}

void init()
{
/*
	if(!query_temp("already_loaded"))
		loadall(this_object());
	return;
*/
}


int accept_fight(object me)
{
	if (is_fighting()){
		command("say 想群殴么？去找山西土匪吧。");
		return 0;
	}
	
	full_me();		
	return 1;
}


int brag()
{
    CHANNEL_D->do_channel(this_object(), "chat",
        "我就是你们的武林总盟主！不服的来试试！\n");
    return 1;
}

void unconcious(){
	die();
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") )
    	ob = this_player(1);
    if( !ob ) return;
	changeshape(ob);
	remove_all_killer();
	return;
}
