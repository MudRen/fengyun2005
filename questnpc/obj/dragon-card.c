#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"青龙令"NOR, ({ "qinglong-ling"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 0);
                set("long",
"这是天下最神秘最庞大的组织：青龙会，为了召开九月初九黑道同盟大会，而火速\n送至天下黑道群豪的青龙令，凭此令则可赴约黑道大会。而山流为了阻止这次黑道盟\n会，征召天下豪杰搜寻这些青龙令。 \n"NOR);
        }
	::init_item();
}

