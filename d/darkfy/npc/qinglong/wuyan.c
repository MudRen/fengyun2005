//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
#include <ansi.h>
inherit SMART_NPC;
int curse_me();

void create()
{
    	set_name("无言",({"wuyan","wu","wu yan"}));
    	set("title",HIG"青龙"NOR);
    	set("nickname",HIY"Married But Available"NOR);
    	set("long","
穿着一件花格子衬衫，头戴一顶鸭舌帽，虽然脸上的笑容很和蔼，但是依然
掩饰不了嘴角的那抹奸笑。\n");
    	set("gender","男性");
    	set("age",37);
    	set("no_arrest",1);
		  set("always_duxin",1);
		  set("combat_exp",20000000);
		  set("attitude","friendly");
      set("reward_npc",1);
		  set("difficulty",50);      
		  set("perform_weapon_attack", "assassin/sword/lefthand-sword/duxin");
		  set("perform_buff_1", "berserker/force/gaunforce/damageup");
		  set("perform_buff_2", "berserker/force/gaunforce/powerup");
			set("perform_buff_3", "berserker/force/gaunforce/forceup");
		  set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     		50: 	(: curse_me() :),
        ]) );    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"无言傲然道：常，是常春藤的常；春，是常春藤的春；藤，是常春藤的藤！。”\n",	
			"无言说道：你知道TJJTDS有四种写法么？"
		}) );
        set_skill("move", 270);
        set_skill("perception", 300);
        set_skill("force", 270);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("parry", 300);
        set_skill("dodge", 280);
        set_skill("magic", 300); 
        set_skill("sword", 300);
        
        set_skill("gaunforce", 200);
		    set_skill("fengyu-piaoxiang", 200);
        set_skill("lefthand-sword", 230);
        
        map_skill("sword","lefthand-sword");
        map_skill("force", "gaunforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","lefthand-sword");
		setup();
    	carry_object("/obj/weapon/sword",([	
    						"name":  HIB"逆刃"NOR,
    						"long": "恩，没想好写什么。\n",
    						 ]))->wield();
    						 
    						 carry_object("/obj/armor/cloth",([	
    						"name":  "鳄鱼T恤",
    						"long": "法国鳄鱼的T-shirt，价值连城。\n",
    						 ]))->wield(); 
    						 carry_object("/obj/armor/hat",([	
    						"name":  "鸭舌帽",
    						"long": "一顶鸭舌帽，看上去很猥琐。\n",
    						 ]))->wield(); 
}


int curse_me() {
	object ob, *enemy;
	ob=this_object();
	enemy=query_enemy();
	switch (random(4)) {
		case 0: message_vision(HIG"\n$N微笑道：人，是人他妈生的；妖，是要妖他妈生的。\n"NOR,ob);
			break;
		case 1: message_vision(HIW"\n$N亲切的问道：你妈贵姓？”\n"NOR,ob);
			break;
		case 2: message_vision(HIR"\n$N叹了口气：只要你有了仁慈的心，你就不再是妖，是人妖。”\n"NOR,ob);
			break;
			case 3: message_vision(HIR"\n$N喃喃说着：去年我在陈家村认识了一位铁匠，\n
				他手工精美、价钱公道、童叟无欺。”\n"NOR,ob);
			break;
	}	
	foreach (object x in enemy){
		tell_object(x,YEL"听着无言的胡言乱语，你觉得头痛的像要裂开来一样。。。。。\n"NOR);
		x->receive_wound("sen",500,ob);
	}
	return 1;
}