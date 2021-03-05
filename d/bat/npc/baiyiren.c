inherit NPC;
#include <ansi.h>


void create()
{
        set_name("东海白衣人", ({ "white cloth man", "man" }) );
        set("nickname", HIC "一剑震神州" NOR );
        set("gender", "男性");
        set("age", 32);
        set("long","
这是一位武功盖世的东瀛武士，曾以一剑横扫中原武林,
所向无敌，后来败在紫衣侯的手中，遂不知其去向。
\n"
        );
        create_family("樱花", 1, "武士");

        set("attitude", "heroism");
        set("combat_exp", 4500000);
        set("score", 200000);
 
		set("reward_npc", 1);
		set("difficulty", 5);
		set("class","ninja");
        set("chat_chance", 1);
        set("chat_msg", ({
			"东海白衣人轻蔑的道：你们中国武士真是不堪一击！\n",
			"东海白衣人傲然道：我代表大和武士向你挑战，敢不敢接受？\n",
			"东海白衣人冷冷道：我一剑就可以横扫你们的江湖！\n",
        }) );

        set("agi",45);
                       
        set_skill("unarmed", 200);
    	set_skill("ghosty-force",300);
    	set_skill("enmeiryu",180);
    	set_skill("ittouryu",160);
    	set_skill("dodge", 180);
		set_skill("ghosty-steps",200);
		set_skill("blade",200);
   		set_skill("force", 180);
    	set_skill("parry", 200);
    	    	   	
    	map_skill("unarmed", "enmeiryu");
    	map_skill("blade", "ittouryu");
    	map_skill("parry", "ittouryu");
   		map_skill("force", "ghosty-force");
   		map_skill("dodge", "ghosty-steps");
   	
   	
   		set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.shiden" :),
                (: perform_action, "unarmed.shimon" :), 
        }) ); 

        setup();
        carry_object("/obj/weapon/sword_katana");
        carry_object("/obj/armor/cloth",
        		([	"name"	:	HIW"樱花武士服"NOR,
        			"armor_prop/armor":	8,
        			"long"	: "一件樱花武士服。\n" ])
        		)->wear();
}

void init(){
		::init();
		add_action("do_answer","answer");
}


int accept_fight(object me)
{
		
		command("say 你是何人？我乃为武道而来，并非来成全你们这些无知莽汉
的愚忠愚死，你们若要求死，只管自己去死吧，还不配我来动手。（answer）\n");
			return 0;
}

int		do_answer(string arg){
		
		object ob, room;
		string msg;
		
		ob = this_player();
		
		if (!room = find_object(AREA_BAT"duelboat"))
			room = load_object(AREA_BAT"duelboat");
		
		if (room->usr_in())
		{
			message_vision(YEL"东海白衣人闭目抚刀，不发一言。\n"NOR, ob);
			return 1;
		}
		
		if (arg == "白三空")
		{
			message_vision(CYN"东海白衣人淡淡地说：既已败了，何必再战。\n"NOR, ob);
			return 1;
		}
		
		if (arg == "死战")
		{
			message_vision(CYN"东海白衣人淡淡地说：死皮赖脸，难道中原武林只有这类货色？\n"NOR, ob);	
			return 1;
		}
		
		if (REWARD_D->riddle_check(ob,"清平剑魂") == 5 
			|| REWARD_D->check_m_success(ob,"清平剑魂") == 2)
		{
			command("say 贪生怕死，你不配我动手。");
			return 1;
		}
			
		if (REWARD_D->riddle_check(ob,"清平剑魂")!=2
			|| (arg != "白三空弟子" && arg != "战死"))	
		{
			message_vision(YEL"东海白衣人冷冷地看了你一眼，面容绝无丝毫表情。\n"NOR,ob);
			return 1;
		}
				
		if ( arg == "白三空弟子" )	{	
			message_vision(CYN"
东海白衣人并不瞧你，挥起长刀，刀尖向天，微微颤抖。
		
东海白衣人说：白三空非我对手，你是他弟子，又怎配和我一战？

东海白衣人说：以你之武功，唯有战死一途。（answer）\n"NOR, ob);
			ob->set_temp("marks/baiyiren_a1",1);
			return 1;
		}

		if (!ob->query_temp("marks/baiyiren_a1"))
		{
			command("say 我乃为武道而来，并非来成全你们这些无知莽汉的愚忠愚死，
你们若要求死，只管自己去死吧，还不配我来动手。\n");
			return 1;
		}

		message_vision(CYN"
$N肃然说：阁下为了研究武学大道，不惜杀人，在下为了武学大道，不惜战死，
殊途而同归，你我本是同路人，今日你纵然将我杀死，我也不怪你！\n\n"NOR, ob);
		ob->delete_temp("marks/baiyiren_a1");
		
		message_vision(CYN"
东海白衣人冷漠如昔，缓缓道：你要送死，我不拦你，你我战于海天之舟！"WHT"

一叶轻舟慢慢从海中驰来。"CYN"

东海白衣人话音乍落，长袖一卷，$N身不由己地向海上飞了出去。\n", ob);

		msg = NATURE_D->game_time()+ "，中原武士"+ ob->name(1)+"约战白衣人于东海之滨。";
		CHANNEL_D->do_sys_channel("info", msg);   		
		ob->move(room);
	
		destruct(this_object());
		return 1;
}
		
		
		
		


		

