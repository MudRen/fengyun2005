inherit NPC;
inherit F_MASTER;
int leave();
#include <ansi.h>

void create()
{
    	set_name("华真真", ({ "hua zhenzhen", "zhenzhen", "hua"}) );
    	set("gender", "女性" );
    	set("long","她斯斯文文，秀秀气气，始终低垂着头，仿佛羞见生人。 
偶然抬头时，一双眼眸如星光般闪动，脸上却现出微微晕红。 \n");

    	set("age", 18);
    	set("per", 30);
    
    	set("reward_npc", 1);
    	set("difficulty", 30);
    
    	set("class","huashan");
    	set("apprentice_available", 50);
    	create_family("华山派", 15, "弟子");
    	set("title", "华山派 第十七代弟子");
		set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"女童","小侠","少侠","女侠","梅使","兰使",
					"竹使","菊使","朝阳女侠","落雁仙女","莲华仙子",
					"五云仙姬",CYN"玉女"NOR,CYN"剑圣"NOR,CYN"剑宗传人"NOR,HIC"剑宗宗主"NOR}));
    	set("inquiry", ([
			"leave" : (: leave :),
	]));
    
       	set("no_busy",10);
    	    
    	set_temp("apply/haste",400);
    	set("guard_msg",HIW"$N叹了口气：杀人者，人杀之！\n"NOR);
    	set("score", 5000);
    	set("combat_exp", 10000000);

    	set_skill("perception", 200);
    	set_skill("move", 190);
    	set_skill("dodge", 200);
    	set_skill("iron-cloth", 180);
    	set_skill("sword", 200);
    	set_skill("throwing", 250);
    	set_skill("foreknowledge",100);
    	set_skill("unarmed",160);
    	set_skill("force", 160);
    	set_skill("literate", 100);
    	set_skill("parry", 160);
    	set_skill("chanting",100);
    	
    	set_skill("hanmei-force", 200);
    	set_skill("anxiang-steps", 180);
    	set_skill("cloud-dance", 200);
    	set_skill("spring-water", 120);
    	set_skill("qingfeng-sword", 200);
    	set_skill("tanzhi-shentong", 160);
    	set_skill("zhaixin-claw",180);
    
    	map_skill("unarmed", "zhaixin-claw");
    	map_skill("force", "hanmei-force");
    	map_skill("dodge", "cloud-dance");
    	map_skill("sword", "qingfeng-sword");
    	map_skill("parry", "qingfeng-sword");
    	map_skill("move", "anxiang-steps");
    	map_skill("iron-cloth", "spring-water");
    	map_skill("throwing", "tanzhi-shentong");
    
    	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                 (: exert_function, "chill" :),
        }) );
        
        
    	setup();
    	carry_object(__DIR__"obj/ycloth")->wear();
    	carry_object(__DIR__"obj/qingfeng")->wield();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } 
}

void do_recruit(object ob)
{
	if((string)ob->query("gender") == "女性" 
			&& ob->query("class")=="huashan" 
			&& REWARD_D->check_m_success(ob,"听琴毛女洞")){      
		if ( ob->query("combat_exp")<1200000) {
			message_vision("$N叹了口气说：华山正在多事之秋，师妹该多努力练功啊， 也许，
等你长大的那一天，我们还会再见面的。 \n",this_object());
			command("wave");
			message_vision("\n\n$N身影一晃，竟然从绝壁边消失了。\n", this_object());
			destruct(this_object());
			return;
		}
				
		if (ob->query("marks/忠诚")==1 
		        || (ob->query("marks/忠诚")== -1 && ob->query("marks/kill_kumei"))
			){
			message_vision("$N盯着$n看了一会儿，叹了口气说：“也许真的有一天，你能发扬光大华山派。” \n",
				this_object(), ob);
			command("recruit " + ob->query("id") );
			message_vision("\n$N转身走到绝壁边，回身向$n示意跟过来。\n", this_object(),ob); 
			message_vision("$N身影一晃，竟然从绝壁边消失了。\n", this_object());
			environment(ob)->go_cliff(ob);
			destruct(this_object());
		}
		else if (ob->query("marks/忠诚")== -1 && !ob->query("marks/kill_kumei")) {
			message_vision("$N盯着$n看了一会儿，叹了口气说：“也许你是忠实的华山弟子，
要知道，本门中的那些见不得人的败类不除掉，华山派就永远不能发扬光大。” \n",
				this_object(), ob);            
			command("wave");
			message_vision("\n\n$N身影一晃，竟然从绝壁边消失了。\n", this_object());
			destruct(this_object());
		}
		
		else {
			message_vision("$N叹了口气说：“华山正在多事之秋，师妹该多为师门出力啊。” \n",
				this_object());
			command("wave");
			message_vision("\n\n$N身影一晃，竟然从绝壁边消失了。\n", this_object());
			destruct(this_object());
		}
		
	} 
	else {
		message_vision("虽然是黑暗的夜色下，$N还是不好意思地低下头，小声说：“ 我才是\n", this_object());
		message_vision("个没出道的弟子，怎么配做别人的师傅呢？” \n", this_object());
		message_vision("$N身影一闪，消失在夜幕中。\n", this_object()); 
		destruct(this_object());
	} 
	return;
}

void init(){
	object ob;
	::init();
	call_out("do_leave", 30);

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_killing", "kill");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if (REWARD_D->riddle_check(ob,"听琴毛女洞") == 4 
		&& (ob->query("marks/忠诚")!= -1 || ob->query("marks/kill_kumei")) )
	{
		message_vision(CYN"$N目注着$n，幽幽一叹。
$N低声道：你也看见了，华山现下正值多事之秋．．．
我曾经那么尊重枯梅师姐，可是，可是．．．．唉．．．
$N说道：师姐她最近行踪诡秘，经常在山后出没，你不妨过去看看。\n\n"NOR,this_object(),ob);
		REWARD_D->riddle_done(ob,"听琴毛女洞",50,1);
	}
}


void do_leave(){
	if( find_call_out("do_recruit") != -1 ) {
		call_out("do_leave", 5);
	}
	environment(this_object())->do_leave();
}


int leave() {
	if (this_player()->query("class")!="huashan") return 0;
	message_vision(CYN"$N低着头说，“好吧“\n"NOR, this_object());
	message_vision(CYN"$N说：只是华山门规森严，春水罗衫和摘心的秘诀不能带走。\n"NOR,this_object());
	return 1;
}