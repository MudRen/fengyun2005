#include <ansi.h>
inherit SMART_NPC;

int dragon_attack();
int dragonstun();
int dragonclaw();
int dragonbreath ();
int dragonblow ();

void create()
{
	set_name("沙海蛰龙", ({ "hibernating dragon", "boss","dragon" }) );
	set("race", "龙");
	set("gender", "雄性");
	set("long", "这本是一条在海底修炼的神龙。因为沧海桑田的变迁，原来的翰海变成
了沙漠。它在这里蛰伏下来，也不知道有几千几万年了。 \n");
	
	set("combat_exp", 15000000);
	
	set("age",10000000);
	set("no_curse",1);
	set("boss",1);
	
	set("agi", 20);
	
	set("max_kee", 300000);
	set("max_gin", 300000);
	set("max_sen", 300000);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10:	(: dragon_attack() :),
        ]) );    	
    	
    	set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
        	(: dragonclaw()	:),
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );  

	set_temp("apply/attack", 800);
	set_temp("apply/armor",  100);
	set_temp("apply/dodge",  600);
	set_temp("apply/damage", 50);
	set("spawn_location","/d/quicksand/shaxue");
	setup();
}


int dragon_attack(){
	if (random(2) && query("is_stunning")+ 4 < time()) 
		dragonstun();
	else if (time()>query("dragon/breath")+12) 
		dragonbreath();
	return 1;
}


int dragonbreath ()	{
	message_vision(HIR"\n\n$N身上忽然发出淡淡的红光，转瞬间，光芒越来越强烈。。。\n\n"NOR,
			this_object());
	call_out("hurting",10);
	set("dragon/breath",time());
	return 1;
}

int hurting()	{
	int i,dam;
	object *inv;
	message_vision(HIR"\n\n$N一张嘴，无数道烈焰迎面向你扑来，闪无可闪，避无可避。\n\n"NOR,this_object());
	inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
		if( living(inv[i]))
		if( inv[i]!= this_object()){
			dam = 3000 + random(2000);
			inv[i]->receive_wound("kee",dam,this_object());
			COMBAT_D->report_status(inv[i]);
        	}
	return 1;
}


int dragonblow()	{
}


int dragonstun()	{
	int i,dam;
	object *inv;
	message_vision(HIW"\n\n$N忽直立而起，又重重跃下，天摇地动，沙穴震颤。。。。\n\n"NOR,this_object());
	inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
		if( living(inv[i]))
		if( inv[i]!= this_object()){
			if (random(this_object()->query("combat_exp"))*5<inv[i]->query("combat_exp"))
				continue;
			inv[i]->perform_busy(2);
			message_vision(YEL"$N只觉心胆俱裂，目瞪口呆，动弹不得。\n"NOR,inv[i]);
        	}
	set("is_stunning",time());
	return 1;
}


int dragonclaw()	{
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	ob->set("bite_time",time());
	enemy=ob->query_enemy();
	me=enemy[random(sizeof(enemy))];
	message_vision(HIG"\n$N举起巨灵般的前爪，挟风雷之势，迅急地向$n的头部一抓。\n"NOR,ob,me);
	me->receive_wound("kee",1000+random(1000),ob);
	COMBAT_D->report_status(me);
	return 1;
}


void die()
{
	object rstone, me,owner,money_reward,skin;
	mapping hate;
	object *ppl, *ppl_present;
	int i;
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
	environment(this_object())->set("dragon_death",time());
	
	// The purpose is, everyone present who contributed hate can get mark
	// the stone ... one at time, give whoever you want :D
	if(objectp(me)) { 
		CHANNEL_D->do_sys_channel("info","一个新的武林神话的诞生。。。。");
		CHANNEL_D->do_sys_channel("info",sprintf("%s，%s于%s%s%s。", NATURE_D->game_time(),
				me->query("name"), environment(this_object())->query("short"),"斩杀", name())); 
	    
	    hate = query_hate_list();
	    if (sizeof(hate))
	    	ppl = keys(hate);
	    if (sizeof(ppl)) {	    
       		ppl_present=filter_array(ppl,(:objectp($1) && userp($1) && environment($1)==environment():));
	    }
	    if (sizeof(ppl_present)) 
	    for (i=0;i<sizeof(ppl_present);i++) 	
	        REWARD_D->riddle_done(ppl_present[i], "蛰龙赤丹", 200, 1);
		
		rstone = new("/obj/specials/stone/rstone");
		if (objectp(rstone)) {
			message_vision(HIR"\n一点红光从沙海蛰龙双目间落下刚好掉入$n手中。\n"NOR, this_object(), me);
			if (!rstone->move(me))
				rstone->move(environment(me));
//			me->set("stone_mark/rstone", 1);
//			rstone->set("stone_owner", me);
			log_file("riddle/IMBUE_LOG",
			sprintf("%s(%s) 揭开 沙海蛰龙 得到蛰龙赤丹 %s \n",
				me->name(1), geteuid(me), ctime(time()) ));			
		}
	} 
	environment(this_object())->tell_exit();	
	::die();
}

