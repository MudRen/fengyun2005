inherit SMART_NPC;
#include <ansi.h>

int smart_fight();

void create()
{
    set_name("身穿黄袍的年青人" , ({ "nanwang prince","prince" }) );
    set("long", "一个很英挺的年轻人，身上穿着件黄袍，下幅是左石开分的八宝\n立水裙。这．．．这难道是当今的天子？当今的天子又怎会在如此一间\n神秘的小屋里？ \n");
	set("attitude", "friendly");
    set("age", 22);
	set("gender", "男性" );
	set("title",HIY"南王世子"NOR);
    set("per",40);
    set("combat_exp", 3000000);
    set_skill("dodge", 200);
    set_skill("fall-steps", 200);
    set_skill("sky-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
	set("NO_KILL","此人有天子威仪，不可胡乱动手，免遭官府追杀。\n");
    map_skill("iron-cloth","henglian");
    map_skill("sword","sky-sword");
	set("nb_chat_chance", 100);
	set("nb_chat_msg_combat", ([
		100: 	(: smart_fight() :),
	]) );    	

	setup();
    carry_object(__DIR__"obj/byrobe")->wear();
    carry_object(__DIR__"obj/hanguang")->wield();
}

void init()
{       
	object ob;
	::init();
	add_action("do_kneel", "kneel");
	add_action("do_reject", "reject");
	if ( interactive(ob = this_player()) && !is_fighting() ) 
	   {
	     remove_call_out("greeting");
	     call_out("greeting", 1, ob);
	   }
}

void greeting(object ob)
{
	if (userp(ob))
		message_vision(HIY"
身穿黄袍的年青人厉声道：朕受命于天，奉诏于先帝，乃九龙之尊，万乘之君！
尔等还不下跪(kneel/reject)！\n"NOR, ob);

}

int do_kneel()
{
	object me = this_player();
	if (me->is_fighting() || me->is_busy())	return 1;
	message_vision("$N哼了一声，挥了挥手：你且退下。\n", this_object()); 
	me->move(load_object("/d/baiyun/changlang2"));
	return 1;
}

int do_reject()
{
	object me;
	me = this_player();
	message_vision(CYN"$N脸色巨变，长啸鸣警，怒喝道：何人如此大胆，来人啊，
给寡人当场斩杀之！ \n"NOR, this_object()); 
	me->kill_ob(this_object());
	this_object()->kill_ob(me);
	smart_fight();
	return 1;
}


int summon_master()
{
	object me=this_object(),room,ye,env=environment(me);
   	message_vision(HIB "\n$N嘶声叫道：叶卿家，还不速来护驾！\n" NOR, me);   
	room=load_object("/d/baiyun/baiyunguan");
	ye = present("master ye",room);
	if (!ye)
		return 0;
	ye->invocation(me,env);
	return 1;
}

void die()
{
	object killer, owner;
	object *enemy, ob;
	int i;
	
	enemy = query_enemy();
	
	if (enemy && sizeof(enemy)>0)
	for (i=0;i<sizeof(enemy);i++) {
		ob = enemy[i];
		if (objectp(enemy[i]->query("possessed")))
			ob = enemy[i]->query("possessed");
		if (!userp(ob)) continue;
		if (REWARD_D->riddle_check(ob,"王图一梦") ==12)
			REWARD_D->riddle_set(ob,"王图一梦",13);	
	}			
	
	if (present("master ye",environment()))
	{
		message_vision(CYN"$N惨叫道：啊～～～～～～～～～\n"NOR, this_object());
		::die();
		return;
	}
	if (!query("summoning"))
	   	summon_master();
	
	if (enemy && sizeof(enemy)>0)
	for (i=0;i<sizeof(enemy);i++) {
		ob = enemy[i];
		if (objectp(enemy[i]->query("possessed")))
			ob = enemy[i]->query("possessed");
		if (!userp(ob)) continue;
		if (REWARD_D->riddle_check(ob,"王图一梦") ==13)
			tell_object(ob,WHT"
你念头飞转，想道：叶孤城剑法卓绝，不可力敌，如今已将这个假圣上解决，
当可阻止叶孤城的阴谋，但叶孤城狼子野心，一计不成，必生他法，到底是
走还是不走？（leave)\n"NOR); 
	}

	::die();
	return;
}

int smart_fight()
{
	object me = this_object(),soldier,*inv;
	int i;
	add_temp("max_guard",1);
	inv=all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("master") == me)
			inv[i]->invocation(me);
	if (!SMART_D->check_health(me,25) && !query("summoning"))
	{
		set("summoning",1);
		summon_master();
	}
	if (query_temp("max_guard") >= 7)	// 最多召唤7个guard.
		return 1;
   	message_vision(HIB "\n$N发出一声长啸求援！\n" NOR, me);   
	seteuid(getuid());
	soldier= new(__DIR__"annguard");
	soldier->move(environment(me));
	message_vision(HIB "\n$N应声而来！\n" NOR, soldier);
	soldier->invocation(me);
	if (soldier)
       	me->remove_all_killer();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
