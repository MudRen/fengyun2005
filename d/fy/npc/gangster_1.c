#include <ansi.h>
#include <combat.h>
inherit NPC;
void goaway();
void playgame();
void blade_pfm(object me, object target);

void create()
{
        set_name("山西劫匪老大", ({ "shanxi laoda","laoda" }) );
        set("nickname","学艺归来");
        set("gender", "男性" );
        set("age", 27);
        
        set("long", "这强盗满脸伤疤，虎背熊腰，一脸凶狠而霸道的样子。");
        set("attitude", "heroism");
        
        set("bellicosity", 1500 );
        set("combat_exp", 10000);
		set("no_lu_letter",1);
		
        set("chat_chance", 50);
        set("chat_msg", ({
		(: goaway :),
        }) );

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
              	(: playgame() :),
        }) );

        set_skill("unarmed", 100);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        set_skill("force",100);
        
        set_skill("demon-steps",100);
        set_skill("demon-blade",120);
        set_skill("demon-strike",120);
        set_skill("demon-force", 100);
        
        map_skill("force","demon-force");
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        map_skill("unarmed","demon-strike");
        
	    setup();
        carry_object(__DIR__"obj/guiblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

void goaway()
{
	object ob;
	if (ob=present("li biaotou",environment()) )
	{
		command("grin");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return; 
	}
		
	message_vision("$N一声唿哨，消失得无影无踪！\n",this_object());
	destruct(this_object());
}


void unconcious()	{ die();}


void	die(){
	
	string *msg = ({
		"\n山西劫匪老大后悔地说：技不如人、技不如人啊。\n",		
		"\n山西劫匪老大捶胸道：早知道就多学几年了。\n",
		"\n山西劫匪老大尖叫：弟兄们，顶住啊！\n",
	});
		
	message_vision(HIR""+ msg[random(3)] + "\n山西劫匪老大死了。\n"NOR, this_object());
	destruct(this_object());
}

void playgame(){
	
	object *inv;
	object me, target;
	int i;
	int tt;
	
	me = this_object();
	
	if (!random(4)) {
		message("vision", HIR"\n"+me->name()+HIR"一招不慎，露出了好大的一个破绽！！！\n"NOR,
	        		environment(me), me);
		me->start_busy(2);
		return;
	}
	
	if (random(6))	tt= 1;
		else tt = 0;	
		
	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv);i++){
		if (tt) {
			if (inv[i]->query("id")=="shanxi gangster")
				target = inv[i];
		}
		if (!tt) {
			if (inv[i]->query_temp("protecting"))
				target = inv[i];
		}
	}
	if (objectp(target)){
		switch (random(3)) {
			case 2:		command("say 小子看招，天地人魔三十六式！"); break;
			case 1:		command("say 终于使出来了！认命吧！"); break;
			case 0: 	command("say 兄弟们，快闪开些，这招太厉害了！"); break;
		}
		blade_pfm(me, target);
	}
}


void blade_pfm(object me, object target){
		
		string msg;
	
		msg = HIY  "\n$N神气贯通，将天地人魔连环八式一气呵成！\n万魔初醒！" NOR;
		
		target->set_temp("no_check_pfm_win",1);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		target->set_temp("skip_damage_record",1);        
        msg = HIY  "魔焰万丈！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "魔光乍现！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "天魔独尊！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "万刃天魔！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "天魔回天！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "天魔七现！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "万魔归宗！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        
        if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record",1);
		}

        me->start_busy(8);
        return;
}
        