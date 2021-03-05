
inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("瘦灰马", ({ "horse" }) );
	set("race", "家畜");
	set("gender", "雄性");
	set("age", 3);
    	set("long", "一匹瘦骨嶙峋的的灰马，毛发失去了往日的光泽。\n");
        
	set("int",40);
	set("cor",80);
	set("str",50);
	set("attitude", "peaceful");
	set("chat_chance", 1);
        set("chat_msg", ({
     			"瘦马＂咴～～咴咴＂地仰天长啸了几声\n",
        }) );
        set("combat_exp", 2000000);
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage",200);
	setup();
}
