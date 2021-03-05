#include <ansi.h>
inherit NPC;

void create()
{
        set_name("孤独美", ({ "gu du mei", "gu du" }) );
        set("nickname", "六亲不认");
        set("title", "独行大盗");
        set("gender", "男性");
        set("age", 56);
        set("no_arrest",1);
        set("long",	"一个两鬓斑白的人，衰老、憔悴、疲倦、悲伤而恐惧。\n");
        setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/sword")->wield();
}

void die(){
	say("孤独美说：我死了，谁都别想活着走出去。\n");
	::die();
}