#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int recruit();
int diqi();

void create()
{
    	set_name("律香川",({"lv xiangchuan","lv"}));
	set("title",WHT"文质彬彬"NOR);
	set("long","
律香川是个脸色苍白，文质彬彬的人。所以别人往往会低估了他的力量，
认为他并没有什么了不起。这种错误不但可笑，而且可怕。律香川不但
是孙玉伯最得力的助手，也是武林中三个最精于暗器的人之一，尤其是
属于机簧一类的暗器，天下再也没有任何人能比得上他。。\n");
   	
     	set("gender","男性");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",9500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
		"高老大":  	(: recruit() :), 
		"gao":  	(: recruit() :), 
		"地契": 		(: diqi() :),
		"laobo":	"老伯就是孙玉伯，没有人真正知道他究竟是个怎么样的人。
这菊园便是老伯的居处，身份不明的人，我们是不会收留的。\n",
		"老伯":		"老伯就是孙玉伯，没有人真正知道他究竟是个怎么样的人。
这菊园便是老伯的居处，身份不明的人，我们是不会收留的。\n",

   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
		set_skill("tanzhi-shentong",160);
		setup();
    	carry_object("obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/throwing/qixing")->wield();
 
}

int recruit(){
	object me,ob = this_object();
	me = this_player();

	if (me->query("timer/菊园失败") + 1440 > time()) {
		command("say 你还有脸回来？\n");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"菊园传奇")) {
		command("say 高老大是快活林的女主人，有空你可以去见见她。");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"菊园传奇")!=1) {
		command("say 好好干，老伯不会亏待你的。\n");
		return 1;
	}
	
	message_vision(CYN"
律香川意味深长地一笑：万鹏王对菊园垂涎已久，老伯正在用人之际。既
然是高老大大力推荐你，就留在这里吧。你的任务是在菊园里四处巡视，
如发现可疑的人事，便需顺藤摸瓜查个水落石出再回报于我。

律香川说：这些日子园子里晚上常常有人影憧憧，你需耐心守候看个明白。
\n"NOR,ob);
	REWARD_D->riddle_set(me,"菊园传奇",2);

	return 1;
}
	
void init()
{       
        object ob;

        ::init();
        if (environment(this_object())->query("home"))
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
	object me, chick;
	int stage;
        
    if( !ob || environment(ob) != environment() ) return;
	
	if (REWARD_D->check_m_success(ob,"菊园传奇"))	return;
		
	stage = REWARD_D->riddle_check(ob,"菊园传奇");
	
	switch (stage) {
		case 0:		command("say 你是什么人，竟然敢私自混入菊园，快快出去吧！");
					return;
					
		case 1:		message_vision(CYN"
律香川锐利的双目看着你，似乎一眼看穿了你的来意。\n"NOR,ob);
					return;
		
		case 2:
		case 3:
		case 5: 		
		case 8:
					command("say "+ ob->name(1)+ "，近来园子里可还有什么可疑之事？\n");			
					return;
					
		case 4: 	message_vision(CYN"
律香川意味深长地说：你守卫菊园有功，替老伯找出了刺客，很好，很好。\n"NOR,ob);
					tell_object(ob,WHT"\n（老伯对你的信任程度提高了！）\n"NOR);
					REWARD_D->riddle_set(ob,"菊园传奇",5);	
					return;
					
		case 6: 	message_vision(CYN"
律香川意味深长地说：韩棠的死我知道了，此乃天意，非人力可扭转，
你忠于职守，做的很好，很好。\n"NOR,ob);
					tell_object(ob,WHT"\n（老伯对你的信任程度提高了！）\n"NOR);
					REWARD_D->riddle_set(ob,"菊园传奇",8);
					return;
		
		case 7: 	message_vision(CYN"
律香川意味深长地说：韩棠的死我知道了，此乃天意，非人力可扭转，
今后老伯的安全就更依托你了。\n"NOR,ob);
					tell_object(ob,WHT"\n（老伯对你的信任程度提高了！）\n"NOR);
					REWARD_D->riddle_set(ob,"菊园传奇",8);
					return;
						
		case 9:		message_vision(CYN"
律香川正色道：陆漫天叛变一事，早在老伯监控之下，而你竟与他沆瀣一气，
实在令人失望，菊园里容不得你，你还是走吧。\n"NOR,ob);
					ob->delete_temp("zangbei/see_lv");
					ob->delete_temp("marks/kuaihuo");
					REWARD_D->riddle_clear(ob,"菊园传奇");
					ob->set("timer/菊园失败",time());
					tell_object(ob,WHT"\n你被赶出了菊园！！！\n"NOR);
					ob->move("/d/zangbei/garden1");
					return;
		
		case 10: 	message_vision(CYN"
律香川意味深长地说：陆漫天叛变一事，早在老伯监控之下，你大义凛然，是
菊园的栋梁之才。\n"NOR,ob);
					command("hmm");
					command("say 但陆漫天不除，终是菊园的心腹大患！");
					return;
		case 11:	message_vision(CYN"
律香川意味深长地说：陆漫天叛变一事，早在老伯监控之下，你大义凛然，是
菊园的栋梁之才。\n"NOR,ob);
					tell_object(ob,WHT"\n（老伯对你的信任程度提高了！）\n"NOR);
					REWARD_D->riddle_set(ob,"菊园传奇",12);
				
		case 12:	if (ob->query_temp("marks/kuaihuo/lv_cook")) {	
						command("say 老伯正在等你，快去吧。");
						return;
					}
							
					message_vision(CYN"
律香川赞赏地说：这一阵子你辛苦了，老伯请你去吃饭。
律香川顿了一顿又道：这只风鸡是我亲手做的，你先拿去给老伯，我马上就到。\n"NOR,ob);
					ob->set_temp("marks/kuaihuo/lv_cook",1);
					chick = new(__DIR__"obj/chicken");
					chick->set("item_owner",ob);
					chick->move(ob);
					return;
		
		}
	
}


int diqi(){
	object me, ob, paper;
	ob = this_object();
	me = this_player();
	
	if (REWARD_D->riddle_check(me,"菊园传奇")!=13) {
		message_vision("$N说：老伯的地产，从不出卖。\n"NOR,ob);
		return 1;
	}
	
	if (me->query_temp("marks/kuaihuo/get_diqi")) {
		message_vision(CYN"律香川说：快活林的地契我不已经给你了么？\n"NOR,ob);
		return 1;
	}
	
	paper = new(__DIR__"obj/diqi");
	if (paper->move(me)) {
		message_vision(CYN"律香川转身拿出一张泛黄的信笺纸递给你，“替我恭喜高老大，她的愿望实现了。”\n"NOR,ob);
		paper->set("item_owner",me);
		me->set_temp("marks/kuaihuo/get_diqi",1);
		return 1;
	} else {
		destruct(paper);
		message_vision(CYN"
律香川说：你有地方放地契么？”\n",NOR,ob);
		return 1;
	}
}


	