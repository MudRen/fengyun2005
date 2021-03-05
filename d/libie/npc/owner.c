#include <ansi.h>
inherit NPC;


void create()
{
        set_name("客栈老板", ({ "lao ban","owner" }) );
        set("long","一个肥肥胖胖的中年人。");
        set("attitude", "friendly");

        set("combat_exp", 100000);

	set_skill("unarmed",150);
	set_skill("parry",150);
	set_skill("dodge",150);
	
	set("inquiry", ([
                "正月初三":	"在下客栈开张那天正是正月初三！\n",
                "di qinglin" : 	"小侯爷就住在楼上麒麟阁。\n",
                "狄青麟" : 	"小侯爷就住在楼上麒麟阁。\n",
                "莲姑" : 	"莲姑是镇上老于头的女儿。\n",
                "杨铮" : 	"杨铮是这儿的捕头，正在破获一百八十万两镖银的大案。\n",
                "yang" : 	"杨铮是这儿的捕头，正在破获一百八十万两镖银的大案。\n",
                "yang zheng" : 	"杨铮是这儿的捕头，正在破获一百八十万两镖银的大案。\n",
        ]));
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"老板擦着柜台叹道：你说杨捕头那么好的人，怎么会是劫镖大盗呢？\n"
        }) );
			
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
