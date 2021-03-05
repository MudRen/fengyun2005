#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int kill_him();

void create()
{
        set_name("什么也不卖的", ({ "bad seller","seller" }) );
        set("gender", "男性" );
        set("age", 40);
		set("combat_exp", 700000);

		set("long","这个人呆呆地坐在路边，面前铺了一块摆小摊儿所用的油布，
油布上写着铁鞭镇三山五个大字，上面空空荡荡，什么货物也没有。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "什么也不卖的慢慢摇头，叹道：不卖，不卖，什么都不卖．．．\n",
        }) );


		set_skill("whip",200);
		set_skill("dragonwhip",125);

		map_skill("whip","dragonwhip");

		set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
              (: perform_action, "whip.thousandfeather" :),
        }) );

        set("inquiry", ([
                "铁鞭镇三山":  (: kill_him :),
                "浪里白条":	"action什么也不卖的慢慢摇头，叹道：不教，不教，什么都不教．．．\n",
                "教":	"action什么也不卖的慢慢摇头，叹道：不教，不教，给我什么都不教．．．\n",				
        ]) );

        set("attitude", "friendly");
        set("vendor_goods", ([
//			__DIR__"obj/niren":20,
        ]) );
        setup();
        carry_object("obj/armor/cloth",([	"name": HIR"血衣"NOR,
    						"long": "一件沾满鲜血的衣服\n",
    						 ]))->wear();  
        carry_object("obj/weapon/whip",([	"name": "铁鞭",
    						"long": "铁鞭镇三山昔年所惯用的兵器。\n",
    						"value": 0,
    						 ]))->wield();  

}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

int kill_him()
{
	object me,ob=this_object();
	me = this_player();
	message_vision("$N身子一震，目视遥远的天际，喃喃道：那都是过去的事了，想我浪里白条．．．\n",ob);
	return 1;
}



int accept_object(object who, object ob)
{
	object oc;
	if (crypt(ob->query("value")+"","ydiN9HFOAOtZ2") != "ydiN9HFOAOtZ2")
	{
			ccommand("shake");
			ccommand("say 什么都不卖，你给我什么也不卖。");
			return 0;
	}
	ccommand("emote 目注"+who->name(1)+"良久，慢慢地叹了口气，点了点头。");
	if (query("still"))
	{
		if (stringp(query("still")))
			ccommand("say 虽然你有诚心想要．．．可是我已经把它给了"+query("still")+"了。");
		else
			ccommand("say 虽然你有诚心想要．．．可是我已经把它给了别人了。");
		
		return 0;
	}
	ccommand("say 既然你有诚心想要，我便送你吧。");
	set("still",who->name());
	oc=new("/obj/book/swimming_50.c");
	oc->move(who);
	ccommand("emote 递给"+who->name(1)+"一本发黄的小册子。");
	return 1;
}

	
void reset(){
	if (!random(4))
		set("still",0);
	
}


 
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

