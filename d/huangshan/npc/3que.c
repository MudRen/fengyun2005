#include <ansi.h>
inherit NPC;

void create()
{
        set_name("轩辕三缺", ({ "san que" }) );
        set("gender", "男性" );
        set("age", 53);
		set("title","独眼单足");
        set("long", "轩辕三成的兄弟，武功高绝，为人心狠手辣。\n");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
		set("difficulty", 5);
		set("attitude", "aggressive");
        set("chat_chance", 1);
        set("chat_msg", ({
             (: random_move :),
         }) );
        set("inquiry", ([
                "萧十一郎" : "我刚刚从他的腿上割下一块肉，他跑了。\n",
				"xiao 11" : "我刚刚从他的腿上割下一块肉，他跑了。\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/qin")->wield();
}
