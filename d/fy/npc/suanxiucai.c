#include <ansi.h>
inherit  NPC;

void  create()
{
	set_name("酸秀才",  ({"suan xiucai","suan","xiucai"}));
//	set("title","小李白");
	set("age",  22);
	set("gender",  "男性");
	set("long", "此人饱读经书，可惜怀才不遇，屡试屡败。\n");
	set("attitude",  "peaceful");
	set("NO_KILL",1);
	set("combat_exp",  8000);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

