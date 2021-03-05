#include <ansi.h>
inherit SMART_NPC;

int do_poison();

void create()
{
	set_name("马贼首领",({"bandit leader","leader"}));
	set("long", "
一个头戴蓝巾，身穿蓝衣的毛脸汉子，一手执着酒杯，一手把玩着三
个卵石般大的黑黝黝的铁蛋，眼光扫过，不怒自威。。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 4500000);
	set("group","bandit");
	
	set("inquiry",([
		"小烟":		"action马贼首领的眼中闪过一丝狐疑之色，小烟？没听说过。\n",
		"司马烟":	"action马贼首领冷笑道：你说的是那个穷凶极恶的司马烟！\n",
	]));
	
    set("nb_chat_chance", 100);
    set("nb_chat_msg_combat", ([
		5: (:do_poison() :),
    ]) );  
		
	set("chat_chance", 1);
    set("chat_msg", ({
    	"马贼首领说：没事儿就走吧，我这儿不留客。\n",
     }) );
     
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(40) :),    
    }) );
	
	auto_npc_setup("guardian",200,175,0,"/obj/weapon/","fighter_w","dragonstrike",1);
	setup();
	carry_object(__DIR__"obj/oldcloth")->wear();	
}


void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer","answer");
}

void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() ) return;
		command("say 无事不登三宝殿，这位。。。找谁？");
}

int do_answer(string arg){
	
	object me;
	
	me = this_player();
	
	if (arg == "小烟"|| arg=="司马小烟") {
		if (!REWARD_D->riddle_check(me,"司马小烟")) {
			command("say 此时与你无关，何必搅此浑水。");
			return 1;
		}
		command("hmm");
		command("say 你说小烟是我的手下劫走，可有证据拿来我看？");
		return 1;
	}
	
	if (arg == "马贼" || arg == "马贼首领"){
		command("shake");
		command("say 不认识你。");
		return 1;
	}
	
	command("say 没听说过");	
	return 1;	
}

int accept_object(object me, object obj){
	int stage;
	
	if (obj->query("24dao")) {
		
		stage = REWARD_D->riddle_check(me,"司马小烟");
		switch (stage) {
			case 0: command("say 此事与你无关，何必搅此浑水。");
					return 1;
			case 1:	command("say 这小孩是谁连你都不知道，拿来给我做甚？");
					return 0;
			case 2: 
			case 3:
			case 4:	command("hmm");
					command("say 不错，那小子是我们的对头，但这不等于说他在我们手中。");
					if (REWARD_D->riddle_check(me,"司马小烟")==2)
						REWARD_D->riddle_set(me,"司马小烟",3);
					return 1;
		}			
	}
	
	if (obj->query("24dao_ren")) {
		stage = REWARD_D->riddle_check(me,"司马小烟");
		switch (stage) {
			case 0: command("say 此事与你无关，何必搅此浑水。");
					return 0;
			case 1:	command("say 这小孩子的玩意儿拿给我做甚？");
					return 0;
			case 2: command("say 这东西和我们有什么关系？");
					return 0;
			case 3:	
			case 4:	command("hmm");
					command("say 好，既然如此，明人不说暗话了。");
					call_out("event1",2,me,0);
					me->start_busy(12);
					return 1;
		}
	}
	
	return 0;
}


string *event1_msg=	({
	CYN"马贼首领说："CYN"我知道你的来意，你是否知道我的来历？\n"NOR,
	CYN"你可知道小烟的父亲是谁？“穿肠剑”司马烟的名字想来你不会陌生。\n"NOR
	CYN"马贼首领的脸上露出怨毒之色，"CYN"我全家一十三口，包括我那未满月的
孩子，都是死在那司马烟的剑下。\n"NOR,
	CYN"马贼首领一指周围，我这几个兄弟，之所以在此潦倒，也是拜司马烟所赐。\n"NOR,
	CYN"我练成武艺，再入恶人谷时，司马贼子竟已病死，我恨我不能手刃这恶人，
所幸苍天有眼，他还留下了个孽种。\n"NOR,
	CYN"马贼首领说："CYN"父债子还，自古如此，更何况此子从小在恶人谷长大，耳闻
目濡皆是穷凶极恶之事，起居住行皆在血腥仇杀之中，若任其长大，又是一
个司马烟，不如就此除去，以绝后患！\n"NOR,
	CYN"此事不必多说，你若执意出头，只有先杀我。\n"NOR,
	});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) 
		|| this_object()->is_fighting() 
		) return;
	
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		tell_object(me, CYN"你已杀了"+chinese_number(me->query("MKS"))+"人，我等自然不会在你眼中。\n"NOR);
		message_vision(YEL"\n马贼首领卡彭一声，将手中的小泥人捏得粉碎。\n"NOR,me);
		if (REWARD_D->riddle_check(me,"司马小烟")==3)
			REWARD_D->riddle_set(me,"司马小烟",4);
			set("poisoned",1);
		return;
	}
	else 
		call_out("event1",1,me,count);
	return ;
}

int do_poison(){
	
	object room;
	
	if (!is_fighting()|| !query("poisoned"))	return 1;
	
	message_vision(CYN"
马贼首领忽然脸色发紫发青，捏住自己的喉咙荷荷地低吼起来，

"HIM"烟雨。。断肠丝。。！"NOR+CYN"

你是司马烟的什么人！

马贼首领叫道：好、好，我死也不会放过你们的。

马贼首领跌跌撞撞地冲进了内帐。

一声凄厉的叫声传了出来，

。。。\n"NOR,this_object());

	room = find_object(AREA_ZANGBEI"innercamp");
	if (!room)	room= load_object(AREA_ZANGBEI"innercamp");
	room->set("poisoned",1);
	this_object()->move(room);	
	::die();
	return 1;
}
	
	
void die(){
	object room;
	remove_all_killer();	
	message_vision(CYN"
马贼首领叫道：好、好，我死也不会放过你们的。

马贼首领跌跌撞撞地冲进了内帐。

一声凄厉的叫声传了出来，

。。。\n"NOR,this_object());

	room = find_object(AREA_ZANGBEI"innercamp");
	if (!room)	room= load_object(AREA_ZANGBEI"innercamp");
	this_object()->move(room);	
	::die();
}

		