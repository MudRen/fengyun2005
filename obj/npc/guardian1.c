#include <ansi.h>

inherit NPC;
void backattack();
void create()
{
        set_name("怨灵护驾", ({ "guardian"}) );
        set("long", "本是地狱中的恶魔，受到邪术士的召唤来到人间。");
        set("race","龙");
        set("attitude", "friendly");
        set("no_fly",1);
        set("no_arrest",1);

        set("str",30);
        set("force_factor",1);
        set("agi",35);
        set("cor",35);
        set("cps",35);
        
        // 容易除去
        set("max_kee",500);
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set("max_gin",500);
        set("gin",query("max_kee"));
        set("eff_gin",query("max_kee"));
        set("max_sen",500);
        set("eff_sen",query("max_kee"));
        set("sen",query("max_kee"));
        
        set("max_force",250);
        set("force",query("max_force")*2);

        set_skill("move",200);
        set_skill("unarmed",100);
        set_skill("dual-attack",100);
        set_skill("demon-strike",100);
        set_temp("apply/haste",100);
        map_skill("unarmed","demon-strike");
        
        set("combat_exp", 50000); 
        
        setup();
        call_out("leave",15);   // 只存在15秒。
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object owner,*pros;
        if (environment())
        message("vision",CYN"怨灵护驾在一瞬间化成一道青光，没进地下。\n" NOR, environment(),this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                                
        destruct(this_object());
}

void invocation(object who, int level)
{
        int i, bonus_skill;
        object *enemy,*pros;

        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
        
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}


void unconcious() {
        die();
}

void die()
{
        leave();
}


void heart_beat()
{
        object leader;
        
        ::heart_beat();
        
        if(!this_object()) 
		return;
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(objectp(query("possessed")))
        {
                leader=query("possessed");
                if(objectp(leader) && environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision(CYN"一道青烟自你身边窜开去．．．\n"NOR,this_object());
                        this_object()->move(environment(leader));
                        message_vision(CYN"一道青烟窜了过来．．．\n"NOR,this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
                else
                        add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
        }
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

