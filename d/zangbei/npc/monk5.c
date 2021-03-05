#include <ansi.h>
inherit SMART_NPC;
int talkshow();

void create()
{
	set_name("直共寺的喇嘛",({"zhigong lama","lama"}));
	set("long", "这是直共寺打扫寺院的喇嘛。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1200000);
	
   	set("inquiry", ([
		"转经":		"绕寺千转，自有所得！\n", 
		"司空掏星": "这猴精贼头狗脑的，我就知道他没安好心。\n",
   	]));
   		
	set("chat_chance", 10);
        set("chat_msg", ({
		(: talkshow() :), 
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(50) :),    
        }) );
	
	auto_npc_setup("wang",120,160,0,"/obj/weapon/","fighter_u","yizhichan",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	
}

int talkshow() {
	object room,*env,ob;
	int i;
	
	ob = this_object();
	env = all_inventory(environment(ob));
	for (i=0;i<sizeof(env);i++) {
		if (userp(env[i])) {
			message_vision("$N往香炉里插了一炷香，低头合手，嘴里不知道在嘟囔些什么。\n",ob);
			return 1;
		}
	}
	
	room=find_object(AREA_ZANGBEI"pine1");
	if (!objectp(room)) room= load_object(AREA_ZANGBEI"pine1");
	message("vision","\n啪地一堆鸟粪掉下，正砸在直共寺的喇嘛头顶。\n",room);
	message("vision","喇嘛四顾无人，指着树顶东南角的鸟窝破口大骂，X你娘，明天老子烧了你！！！\n",room);
	env=all_inventory(room);
	for (i=0;i<sizeof(env);i++)
		if(userp(env[i])) env[i]->set_temp("marks/zangbei/树顶",1);
	return 1;
}

