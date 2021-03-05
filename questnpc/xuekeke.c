#include <ansi.h>
inherit QUESTNPC;
int give_mail();
void create()
{
        set_name("薛可可", ({ "xue keke","xue" }) );
	set("nickname",HIC"月光如水"NOR);
        set("title","月神山庄   大小姐");
	set("gender", "女性");
        set("quality","good");
        set("age",19);
        set("combat_exp", 5800000);
         set("long",
"月色水波间，仿佛有层淡淡的烟雾升起，烟雾间仿佛有一条淡淡的人影。云开，
月现，月光谈淡的照下来，恰巧照在她的脸上。苍白的股，苍白如月。\n"
        );
        set("max_force",5000);
        set("force",5000);
        set("force_factor",150);
		set("max_gin",3200);
		set("max_sen",3200);
		set("con",40);
		set("int",27);
        set_skill("move",150);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",150);
		set_skill("moon-blade",120);
        map_skill("dodge","moon-blade");
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        set("chat_chance", 15);
        set("chat_msg", ({
 "薛可可面对着黑暗的苍穹淡淡地道：“太阳是生，月是死，我相信此时
此刻，在那一座小楼的灯光下，他也一定在等待着月与死”\n",     }) );


        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
			(:perform_action,"blade.yueshen-feidao":),
        }) );
		set("inquiry",([
			"李坏":(:give_mail:),
			])	);
        setup();
        carry_object(__DIR__"obj/yueshencloth")->wear();
        carry_object(__DIR__"obj/yueshenblade")->wield();
}

int give_mail()
{		object letter;

		command("sigh");
		command("say 天下本来就有许多事情，有时候即使知道不对，也得做下去。");
		if(!this_object()->query("mail_given"))
		{
			letter=new(__DIR__"obj/zhanshu");
			message_vision("$N对$n说道：“请帮我把这封信交给李坏。”",this_object(),this_player());
			letter->move(this_player());
			this_object()->set("mail_given");
		}
		return 1;
}