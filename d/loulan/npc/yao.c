#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave();

void create()
{
	set_name("小蓟", ({ "xiao ji","xiaoji" }) );
	set("gender", "女性" );
	set("long","美目流转，巧笑倩兮。
谁也无法想到，她就是快活林中地位最高行踪也最缥缈的药使。\n"
	);
        create_family("快活林", 3, "药使");
        set("nickname", MAG "年华似水"NOR);
        set("attitude", "peaceful");
        set("rank_nogen",1);
        set("class","knight");
        
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"侍酒童","寻欢客","敛财客","药师","铁骑士","铁骑卫",
    			"铁骑统领","铁骑使","酒使","色使","财使","气使",
    			RED"快活右使"NOR,RED"快活左使"NOR,RED"一字并肩王"NOR,HIR"快活王"NOR}));
	
		set("reward_npc", 1);
		set("difficulty", 5);
    	
    	
		set("chat_chance_combat",80);
		set("chat_msg_combat",({
        	(:perform_action,"herb.canyunbi":),
          (:perform_action,"axe.pangukaitian":),
        	(:perform_action,"herb.kaixiehua":),
		}));
	
		set("age", 23);
        set("per", 4);
                
        set("combat_exp", 9500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "小蓟不屑地哼了一声：连个天山雪莲都没有，居然还没倒闭？\n",
                "小蓟叹道：还是中原的水土养人啊，呆了这些日子皮肤白了不少那。\n",
                "小蓟不屑到：云南白药？拿来治牲口的药人也能吃？？？？\n",
        }) );
        
        set("inquiry", ([
    
    	]));
        
        set_skill("foreknowledge",100);
        set_skill("unarmed", 100);
        set_skill("force", 120);
        set_skill("longlife-force", 130);
        set_skill("axe", 200);
        set_skill("xuanyuan-axe", 130);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("literate",100);
        set_skill("chanting",100);
        set_skill("windy-steps", 130);
        set_skill("hanshan-strike", 120);
        set_skill("perception", 100);
        set_skill("dream-herb",100);
        set_skill("herb",100);
        
        map_skill("herb","dream-herb");
        map_skill("dodge", "windy-steps");
        map_skill("unarmed", "hanshan-strike");
        map_skill("force", "longlife-force");
        map_skill("axe", "xuanyuan-axe");
        map_skill("parry", "xuanyuan-axe");
        
        setup();
  		carry_object("/obj/weapon/axe_l")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
}

void attempt_apprentice(object me)
{
	command("say 乖徒弟 :)");
	command("pat " + me->query("id") );
  command("recruit " + me->query("id") );
    tell_object(me,"小蓟在你的耳边悄声说道：玉门关北面熊猫儿处，踏入（wade）沙流，便可一窥昔日楼兰遗址！\n");
    tell_object(me,"小蓟在你的耳边悄声说道：我还要在外面云游一些时间。\n");
    tell_object(me,"小蓟在你的耳边悄声说道：你可回去找独孤伤，传授你更高深的武学。\n");
	return;
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
    	ob->set("class", "knight");
}

int accept_fight(object me)
{
        object ob;
        ob = this_object();
	
	 {
	 	command("heng");
		command("say 别来送死！");
		return 0;
	}

   
}



