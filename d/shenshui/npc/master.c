//XXDER

inherit NPC;
inherit F_MASTER;
int leave();

#include <ansi.h>

void create()
{
    	set_name("白水娘娘", ({ "master baishui", "master", "baishui" }) );
       	set("gender", "女性");
    	set("class", "shenshui");
    	set("age", 53);
    	set("long","
一个人端坐寝宫的中央，她身上穿着千百层薄如蝉羽般的轻纱，面上也覆着十余
层轻纱。虽然无风，但轻纱仍不住在飘动，她虽然坐在那里动也末动，但整个人
却似已要羽化登仙，乘风而去。她看来正如雾中的精灵，云中的仙子。\n");
    	set("attitude", "peaceful");
    	set("class", "shenshui");
    	   
    	create_family("神水宫", 11, "掌门");
    	set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"采莲女","侍女","小仙女","仙女","绛衣仙子","橙衣仙子",
			"青衣仙子","白衣仙子","神姬","仙姬","魔姬","妖姬",RED"绝代妖姬"NOR,
			RED"九阴姹女"NOR,RED"癸宗传人"NOR,HIR"癸宗宗主"NOR}));
					
    	set("reward_npc", 1);
	set("difficulty", 30);
    	set("inquiry", ([
        	"leave" : (: leave :),
    	]));  
	
    	set("per", 40);
    	    	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
        	(: perform_action, "dodge.lianhuanbu" :),
         }) );
    

    	set("combat_exp", 15000000);
    	set("score", random(90000));

		set_skill("unarmed", 180);
		
		set_skill("advanced-unarmed", 200);
		
		set_skill("chanting", 150);
		set_skill("foreknowledge",100);
		set_skill("perception",100);
		set_skill("sword", 300);
		set_skill("force", 160);
		set_skill("parry", 200);
		set_skill("dodge", 160);
		set_skill("move",160);
		set_skill("literate",100);
		    
		set_skill("nine-moon-spirit", 200);	
		set_skill("nine-moon-sword", 200);
		set_skill("nine-moon-claw", 200);
		set_skill("nine-moon-steps", 180);
		set_skill("nine-moon-force", 180);
		    
		map_skill("dodge", "nine-moon-steps");
		map_skill("unarmed", "nine-moon-claw");
		map_skill("force", "nine-moon-force");
		map_skill("sword", "nine-moon-sword");
		map_skill("move","nine-moon-steps");

	
		set_temp("nine-moon-force_poison", 500);
    	set_temp("damage_shield/type","kee");
		set_temp("damage_shield/amount",250);
		set_temp("damage_shield/msg",MAG"$n似乎沾上了$N周围的毒雾，手脚开始不灵便起来。\n"NOR);
	
    	set_temp("apply/dodge", 100);
		set_temp("apply/parry", 100);

    	setup();
    	carry_object(__DIR__"obj/ghostyboots")->wear();
    	carry_object(__DIR__"obj/ghostycloth")->wear();
    	carry_object(__DIR__"obj/ghostygirth")->wear();
    	carry_object(__DIR__"obj/ghostyribbon")->wear();
}


void attempt_apprentice(object ob)
{
   	if (ob->query("class")!= "shenshui") 
   		message_vision(CYN"白水娘娘看了看$N说：神水宫不收来历不明的人。\n"NOR,ob);
   	else if( ob->query("gender") != "女性" )
    	{
		command("shake");
		command("say 神水宫的武功，非女子不能修炼到至高境界。");

	} else if (F_LEVEL->get_level(ob->query("combat_exp"))< 66) {
		command("say 你的武功火候不够，还需多加磨练才是（需66级）。");
	} else	if (!REWARD_D->check_m_success( ob, "清平剑魂")) {
		command("say "WHT"扶桑白衣人"CYN"重入中原，你可速去清平剑客处请战。");
		if (!REWARD_D->riddle_check(ob,"清平剑魂"))
			REWARD_D->riddle_set(ob,"清平剑魂",1);
	} else			
	{
        	command("smile");
        	command("say 很好，很好，很好。");
        	command("recruit " + ob->query("id") );
			tell_object(ob, CYN"\n你只听一个细微的声音传了过来：“你即已入我神水，当知神水密径。\n"NOR);
   			tell_object(ob, CYN"出神水可由火岩洞口处推开山石，回路则由清平山庄密林，谨记、谨记。\n"NOR);
   			message("vision", ob->name()+ "似乎在侧耳聆听什么，你却什么也听不到。\n", environment(ob), ob);
   	}
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
}


int leave() {
	if (this_player()->query("class")!="shenshui") return 0;
	message_vision(CYN"$N说：想走可以，但从此不能在江湖上使用九阴神功。\n"NOR,this_object(),this_player());
	return 1;
}