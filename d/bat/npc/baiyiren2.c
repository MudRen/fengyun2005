inherit SMART_NPC;

#include <ansi.h>

void check_fight();
void check_death();

void create()
{
        set_name("东海白衣人", ({ "white cloth man", "man" }) );
        set("nickname", HIC "一剑震神州" NOR );
        set("gender", "男性");
        set("age", 32);
        set("long","
这是一位武功盖世的东瀛武士，曾以一剑横扫中原武林，所向无敌，
后来败在紫衣侯的手中，遂不知其去向。
\n"
        );
        create_family("樱花", 1, "武士");

        set("attitude", "heroism");
        set("combat_exp", 10000000);
 
		set("reward_npc", 1);
		set("difficulty", 5);
		set("class","ninja");

        set("agi",45);
                       
        set_skill("unarmed", 200);
    	set_skill("ghosty-force",300);
    	set_skill("enmeiryu",200);
    	set_skill("ittouryu",200);
    	set_skill("dodge", 200);
		set_skill("ghosty-steps",200);
		set_skill("blade",200);
   		set_skill("force", 180);
    	set_skill("parry", 200);
    	    	   	
    	map_skill("unarmed", "enmeiryu");
    	map_skill("blade", "ittouryu");
    	map_skill("parry", "ittouryu");
   		map_skill("force", "ghosty-force");
   		map_skill("dodge", "ghosty-steps");   	
   	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			100: 	(: check_death() :),
        ]) );   		

   		set("chat_chance", 0);
        set("chat_msg", ({
             (: check_fight() :),
                
        }) ); 
        
        set("asked",1);
   	    setup();
        carry_object("/obj/weapon/sword_katana")->wield();
        carry_object("/obj/armor/cloth",
        		([	"name"	:	HIW"樱花武士服"NOR,
        			"armor_prop/armor":	8,
        			"long"	: "一件樱花武士服。\n" ])
        		)->wear();
}

void init(){
		object ob;
		add_action("do_kneel", "kneel");
		if (interactive(ob=this_player()))
		{
			message_vision(WHT"
白衣人霍然转身，突然露出一种说不出的厌倦之意，似乎是因为这种场
合他已经历得太多，又似乎因为他已胜得太多。

白衣人淡淡一笑，道：

    “你能么，但愿你能……”

\n"NOR, ob);
			this_object()->set("chat_chance",100);
			set("asked",0);
		}	
		::init();
}

int 	do_kneel(){
	
		object me = this_player();
		object room;
		string msg;
		
		
		if (!me->query_temp("marks/baiyiren_beg"))	return 0;
		
		tell_object(me,"你左思右想，还是保命要紧。\n");
		message_vision(YEL"\n$N扑通一声跪倒在地：白衣大侠在上，中原武人"+ me->name(1)+"技不如人，心服口服，
求大侠高抬贵手，饶小的一条命，从此不敢再与东瀛武士为敌。\n"NOR, me);
		
		message_vision(WHT"\n\n白衣人冷冷道：我战的是武人，而非小人，你滚吧。
		
		
"YEL"一股大力涌来，你腾云驾雾地从小船上飞了出去。。。。\n\n\n"NOR, me);

		room = find_object("/d/bat/renjiandao3");
		if (!room) room = load_object("/d/bat/renjiandao3");
		
		msg = NATURE_D->game_time()+ "，"+ me->name(1)+"贪生怕死，在白衣人刀下苟延一条小命。";
		CHANNEL_D->do_sys_channel("info", msg);   
		 	
		if (REWARD_D->riddle_check(me,"清平剑魂")==2)
				REWARD_D->riddle_set(me,"清平剑魂",5);
		me->delete_temp("marks/baiyiren_beg");
		me->unconcious();
		me->move(room);
		set("asked",0);
		remove_call_out("resume_fight");
		return 1;
}
		


void	check_death() 	{
	
		object *enemy;
				
		if (query("asked"))	return;
		enemy = query_enemy();	// SS should be only one.
		if (!enemy || sizeof(enemy)>1)	return;
		if (enemy[0]->query("kee") <= enemy[0]->query("max_kee")*60/100)
		{
			set("asked", 1);
			set("chat_chance", 0);
			enemy[0]->remove_all_killer();
			message_vision(WHT"
白衣人手持长刀，站在那里，他背后是一望无尽的大海，他面对着的，
却是当今天下武林的英雄，

在茫茫的海洋与莽莽英豪间，他看来显然更孤立，更寂寞，他目光落
寞地四下转动着，冷冷道：

    “七年……七年来中土武林之武功，为何非但全无精进，反而后
退了，紫衣候一死，难道竟真的后继无人？”\n\n"NOR, this_object());

			message_vision(CYN"
白衣人嘴角突然泛起一丝诡异的笑容，一宇字缓缓道：你武功低微，非
我对手，你若跪下认输，我便放你一条生路。（kneel)\n"NOR, enemy[0]);
			set("NO_KILL","白衣人正在问你话呢。\n");
			enemy[0]->set_temp("marks/baiyiren_beg",1);
			call_out("resume_fight", 20, enemy[0]);
			return;
		}
		return;
}

void resume_fight(object me){
	set("chat_chance", 100);
	me->delete_temp("marks/baiyiren_beg",1);
	message_vision(CYN"\n\n白衣人冷冷道：既然你愿为武道而死，我就成全你。\n"NOR, this_object());
}

			
		
int accept_fight(object me)
{
		command("heihei");
		return 0;
}

void 	check_fight()	{
		
		object *inv, ob;
		int i;
		
		inv= all_inventory(environment());
		
		for (i=0;i<sizeof(inv);i++){
			if (userp(inv[i]))
			{
				delete("NO_KILL");
				ob = inv[i];
				ob->kill_ob(this_object());
				this_object()->kill_ob(ob);
				return;
			}
		}
		
		set("chat_chance", 0);
		return;
}

//		你能杀是你本事，你杀不了我也不勉强你，--*好人 silencer
		
void	killed_enemy(object victim) {

		message_vision(WHT"
白衣人仰视着蓝天高处一朵飘渺的白云，悠悠道：

“你永远不会知道，像我这样的人活在世上，是多么寂寞…。”\n\n"NOR, this_object());
	
		if (!userp(victim))	return;
		if (REWARD_D->riddle_check( victim,"清平剑魂")==2)
			REWARD_D->riddle_set(victim,"清平剑魂",3);
		
		return;
}

void	die() {
		
		object killer;	// SS has no pet.
		
		killer = this_object()->query_temp("last_damage_from");
		
		message_vision(WHT"
白衣人仰视着蓝天高处一朵飘渺的白云，悠悠道：

“你永远不会知道，像我这样的人活在世上，是多么寂寞…。”\n\n"NOR, this_object());
	
		if (objectp(killer))
		{
			if (REWARD_D->riddle_check( killer,"清平剑魂")==2)
				REWARD_D->riddle_set(killer,"清平剑魂",4);
		}
		
		::die();
		return;
		
}
