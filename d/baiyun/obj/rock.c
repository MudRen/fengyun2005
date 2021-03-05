inherit ITEM;

#include <ansi.h>
void create()
{
    set_name("礁石", ({ "rock" , "礁石","怒礁"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "块");
        set("long", "一块历经千年沧桑的礁石，上面竟以人力铁钩银划般刻着数行大字：
\n\n"+HIC"                飘飘何所似\n\n"NOR+HIY"                     天地一沙鸥\n\n"NOR+"
    余得破至道，本无所撼，然四十余载亲传五徒，尽皆羁绊于尘世欲念！
    首徒孤城，天纵奇才，以弱冠之龄便初悟剑道极至。然一心王图，不诚于心，
何诚于剑？其余四子，终是解不开一段宿世孽缘，呜乎哀哉，无缘仙道，奈若何
之？字谕有缘，若解五子尘结！老朽之人，再无憾矣！\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
