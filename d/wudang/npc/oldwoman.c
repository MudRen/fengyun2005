#include <ansi.h>
inherit NPC;
int send_fan();

void create()
{
        set_name("老妇人", ({ "old woman", "woman" }) );
        set("gender", "女性");
        set("age", 49);
        set("long",	"老妇人正在忙着做饭。\n");
        set("attitude", "peaceful");
        set("combat_exp",2000);
        set("inquiry", ([
				"help" : (: send_fan :),
				"帮忙" : (: send_fan :),
				"饭" : 	(: send_fan :),
                "送饭":	(: send_fan :),
                "饭菜" : (: send_fan :),
				"老伴" : "他还在庄稼地里干活，连饭都忘了吃。",
				"rice":	(: send_fan :),
        ]) );
        set("count",0);
        setup();
    	carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/basket2");
}

int send_fan()
{
        object ppl, bag, me, rice, vege, chop;
		string lastname;
		int count;
		
		me = this_player();
		
		ppl = query("lastone");
		if (objectp(ppl))
			lastname = ppl->name(1);
		else 
			lastname = "有人";
		
		if (me==ppl) {
			command("say 我不是刚叫你送饭么？送到了吗？");
			return 1;
		}	
		
		if (query("count")>=3) {
			command("say 多谢这位"+ RANK_D->query_respect(me) + "，不过，"+lastname+"已经替我送过饭了。\n");
			return 1;
		}
		
		message_vision("老妇人高兴的指指地上的饭篮说：请这位" + RANK_D->query_respect(me) +"把这个给我"YEL"老伴"NOR"送去好吗？\n",me);
		bag = new(__DIR__"obj/basket2");
		rice = new(__DIR__"obj/rice");
		vege = new(__DIR__"obj/vege");
		chop = new(__DIR__"obj/chopstick");
		rice->move(bag);
		vege->move(bag);
		chop->move(bag);
		bag->move(environment());
		set("lastone",me);
		count = query("count");
		count++;
		set("count",count);
		return 1;
}

void reset(){
	delete("lastone");
	delete("count");
}
