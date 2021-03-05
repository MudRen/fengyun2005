#include <ansi.h>
inherit NPC;
int kill_object();

void create()
{
        set_name("何雅风", ({ "he yafeng","yafeng","he" }) );
        set("gender", "男性" );
        set("age", 34);
        set("str", 40);
   
        set("long",
"他看上去象文质彬彬的书生，年纪并不太大，长得非常英俊，而且风
度翩翩，温文有礼。\n\n");

        set("combat_exp", 100000);
        set("attitude", "friendly");
	set("fly_target",1);

        set("max_atman", 100);         
        set("atman", 100);             

        set("chat_chance", 1 );
        set("chat_msg", ({
"何雅风漫声长吟着：“远上寒山石径斜，白云深处有人家，\n
停车坐看枫林晚，霜叶红于二月花．．．．．．\n
好一片风光呀，好一处所在。”\n\n",
        }) );

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);

        set("inquiry", ([
                "梅汝甲": (:kill_object:),
                "金狮子": (:kill_object:),
		"夹棍": (:kill_object:),
		"凤栖梧": (:kill_object:),
		"麦老广的财宝": (:kill_object:),
        ]) );
		  
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int kill_object()
{	object meirujia;
	if (!this_player()->query("marks/meirujia"))
		{
			command("shake");
			command("say 我不知道你在说些什么。");
			return 1;
		}
	else
		{
			command(":P");
			command("say 原来你都知道了，今天有你没我，有我没你！！");
			meirujia=new(__DIR__"meirujia2");
			meirujia->move(environment(this_object()));
			meirujia->kill_ob(this_player());
			destruct(this_object());
			return 1;			
		}
}
