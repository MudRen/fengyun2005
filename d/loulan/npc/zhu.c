#include <ansi.h>
inherit SMART_NPC;

void create()
{
    set_name("朱七七", ({ "zhu qiqi","zhu" }) );
    set("gender", "女性" );
    set("title", "朱家七小姐" );
    set("nickname", HIC"天若有情天亦老"NOR );
    set("long",
      "白衣白裙，一张俏脸却白里透红，体态婀娜，面容娇美，着实是无法形容，\n若非眼见，谁也难信人间竟有如此绝色。\n"
    );
    set("attitude", "peaceful");
    set("class","legend");
    set("age", 19);
    set("per", 70);
    set("combat_exp", 600000);

    set("chat_chance", 1);
    set("chat_msg", ({
	"朱七七俏目含泪，轻声骂道：黑心鬼，死没良心的，你和那白飞飞，到底怎么了。。。 \n",
	"朱七七擦了擦眼泪，喃喃道：死猫，瘟猫，癫皮猫，这要紧关头又不知死到哪儿去了？\n",
	"朱七七杏目圆睁，啐了一口王怜花道：要不是你们这两个妖魔兄妹，沈浪又怎会被抓住。\n",
      }) );

    set_skill("unarmed", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("move", 150);
    set_skill("fall-steps", 100);
    set_skill("meihua-shou", 100);
    map_skill("dodge", "fall-steps");
    map_skill("unarmed", "meihua-shou");

		set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
    setup();
    carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{	
    if( obj->query("name") == WHT"玉璧"NOR && obj->query("item_owner") == "沈浪" )
    {
	message_vision("$N捏紧玉璧，悲喜交集，哇得哭出声来．．．\n",this_object());
	if(me->query_temp("marks/chai_get_jade"))
	{
	    message_vision("$N向$n说道：请帮帮我，不要让沈浪被白飞飞给骗了．．．\n",this_object(),me);
	    me->set_temp("marks/jade_to_zhu",1);
	    me->delete_temp("marks/chai_get_jade");
	    return 1;
	}
	else
	{
	    tell_object(me,"朱七七俏目含泪：他还没有忘记我...呜...\n");
	    return 1;
	}
    }
    else
    {
	tell_object(me,"朱七七摇了摇头，看都不看你一眼！\n");
	return 0;
    }	
}
