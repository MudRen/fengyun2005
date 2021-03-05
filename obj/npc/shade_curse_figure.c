#include <ansi.h>
inherit NPC;

void loadall(object me);
void changeshape(object winner);

void create()
{
	string info,name,id,file;
        set_name( "影子" , ({ "shadefigure" }) );
	setup();
}

void changeshape( object winner)
{
	string winner_file;
	string name,id;
	
	if(!stringp(winner_file = winner->query_save_file()))
		return;

	seteuid(getuid());
	restore_object(winner_file);
	name = winner->query("name");
	id = "shade " + winner->query("id");	// Tons of trouble about query_killer() if using same id.
	set_name( name , ({ id }) );
	
	delete("env");
	delete("marry");
	
	reset_action();
	delete_temp("already_loaded");
	loadall(this_object());	
	setup();
    return ;
}

void loadall(object me)
{
        string name,id, *created;
        int i,j;
        object thing, *inv;
		inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        	destruct(inv[i]);
        me->reset_action();
        me->set_temp("already_loaded",1);
}

void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
			enemy = this_object()->query_enemy();
	        i = sizeof(enemy);
	        if (i)
	        while(i--) {
	                if( enemy[i] && living(enemy[i]) ) {
	                	if (COMBAT_D->legitimate_kill(enemy[i],owner)) {
		                        owner->kill_ob(enemy[i]);
		                        enemy[i]->kill_ob(owner);
	                	}
	                }
	        }

	}
}

void die()
{
    object ob;
	message_vision("$N死了，却没有看到尸体，原来只是一个幻影而已。\n",this_object());
	if(ob=this_object()->query("owner"))
	{
		tell_object(ob,HIY"\n你的分身被人杀死了。\n"NOR);
		backattack();
		if (ob->query("env/invisibility")>0)	
			ob->add("env/invisibility",-1);
		if( ob->query_temp("figureshade"))
			ob->delete_temp("figureshade");
		if (ob->query_temp("no_move"))
			ob->delete_temp("no_move");			
	}
	destruct(this_object());
}

void disappear()
{
	message_vision(CYN"$N慢慢的透明，消失。。。原来只是一个幻影而已。\n"NOR,this_object());
	backattack();
	destruct(this_object());
}

