// tea_waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

int quest();

void create()
{
        set_name("陆羽", ({ "lu yu","lu","waiter" }) );
        set("gender", "男性" );
        set("title","茶中仙");
        set("age", 40);
        set("long", "陆羽正忙着招呼客人, 一手提着茶壶, 一手拿着抹布。\n");
		set("NO_KILL","此人太重要，杀了谁给你泡茶？\n");
		set("combat_exp", 3000);
        set("attitude", "friendly");
        set("rank_info/respect", "茶中仙");
        set("vendor_goods", ([
//                "/obj/medicine/party/pill_qingtuan": 50,
                "/obj/food_item/luteapot": 50,
                "/obj/food_item/dumpling": 50,
                "/obj/food_item/chicken_leg": 50,
// "/obj/wiz_toy/taskstone1": 150,
                __DIR__"obj/longjin":50,
        ]) );
        set("inquiry", ([
        	"水质":		(:quest:),
        	"job":		(:quest:),
        	"烦恼":		(:quest:),
        ]));	
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "陆羽笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "陆羽用毛巾抹了抹靠门的一张桌子，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "陆羽说道：这位" + RANK_D->query_respect(ob)
                                + "，进来尝尝才采的新茶叶。哇! 好香啊!...\n");
                        break;
        }
}

int quest(){

	object me = this_player();
	object teapot;
	string pos, area, water;
	// 0-22 easy, 23-30 run more, 31-36 run even more
	
	string *source = ({ "三清山:三清湖水",
						"三清山:龙潭瀑水",
						"千佛山:山泉水",
						"武当山:剑泉水",
						"万梅山庄:小井水",
						"万梅山庄:热水",
						"铁雪山庄:梅雨潭水",
						"桃源:清潭水",
						"藏北沙漠:古董滩水",
						"华山:玉泉水",
						"新疆:柴容堡湖水",
						"新疆:清澈的溪水",
						"帝王谷:翠竹溪水",
						"帝王谷:流泉水",
						"太平镇:沼泽水",
						"沉香镇:小河流水",
						"黄山:云雾溪水",
						"黄山:人字瀑水",
						"济南:趵突泉水",
						"济南:大明湖水",
						"济南:莲花池水",
						"狼山:鹰愁涧水",
						"富贵山庄:山涧水",		// 可假冒
//						"富贵山庄:沥泉水",	  too hard
						
						"明霞山:石精",
//						"相思山:不老寒泉",
//						"相思山:清池凝露",
						"相思山:清溪水",
						"黄山:三叠泉水",
						"白云岛:三仙泉水",
						"白云岛:潜龙泉水",
						"华山:小溪水",
						"藏北草原:桑堆河水",
						
						"关外:冰水",
						"泰山:山涧水",
						"少林:甘露水",
						"岱庙:雨花井水",
						"泰山:黄叶潭水",
						"藏北沙漠:小池塘水",
					});
					
						
	message_vision("陆羽摇摇头说：这城里的水质是一天不如一天了，没有好水，怎么泡好茶！\n\n", me);
	
	if (!QUESTS_D->verify_quest(me,"勘探水质"))
		return 1;
	
	if ( me->query("quest/quest")!="勘探水质")
		return 1;
		
	if (me->query("combat_exp")< 50000)	pos = source[random(23)];
	else if (me->query("combat_exp")< 100000) pos = source[23 + random(7)];
	else pos = source[30+ random(6)];
	
	if (sizeof(me->query_temp("luyu"))){
		tell_object(me,CYN"陆羽说：我交给你做的事儿办完了么？你要到"+ me->query_temp("luyu/area") +"，
用眉峰聚的茶壶打一壶" + me->query_temp("luyu/water") + "回来。\n"NOR);
		return 1;
	}	
	
	if (sscanf(pos,"%s:%s", area, water)!=2)
		return notify_fail("Please inform wizard about this bug.\n");
	
	me->set_temp("luyu/area",area);
	me->set_temp("luyu/water",water);
	me->set("quest/short","用眉峰聚的茶壶到"+ me->query_temp("luyu/area")+"打一壶"+
me->query_temp("luyu/water")+"回来交给陆羽");
	
	tell_object(me,CYN"陆羽说：你能不能帮我个忙，到"+ me->query_temp("luyu/area") + "，
用眉峰聚的茶壶打一壶" + me->query_temp("luyu/water") + "回来。\n");	
	tell_object(me,"陆羽说：我想看看是不是以后就从那儿运水过来。\n"NOR);	
	return 1;	
}

int accept_object( object me, object ob){

	if (ob->query("name")!="茶壶")	return 0;
	
	if (!QUESTS_D->verify_quest(me,"勘探水质")) return 0;
		
		
	if (ob->query("mark")!= "luyu") {
		command("say 哎呀，怎么没用我眉峰聚的茶壶，这不全糟塌了么！");
		return 0;
	}
	
	if (ob->query("liquid/name")!= me->query_temp("luyu/water")){
		command("say 这不是我要试的水。\n");
		return 0;
	}
	
	me->delete_temp("luyu");
	command("touch "+ me->query("id"));
	command("say 太谢谢了，我这就去泡壶茶尝尝。");
		
	if (QUESTS_D->verify_quest(me,"勘探水质"))
		QUESTS_D->special_reward(me,"勘探水质");
			
	return 1;

}


void reset(){
	        set("vendor_goods", ([
//	        			"/obj/medicine/party/pill_qingtuan": 50,
                "/obj/food_item/luteapot": 50,
                "/obj/food_item/dumpling": 50,
                "/obj/food_item/chicken_leg": 50,
                __DIR__"obj/longjin":50,
// "/obj/wiz_toy/taskstone1": 150,
        ]) );
}