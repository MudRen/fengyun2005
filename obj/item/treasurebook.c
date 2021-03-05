#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("怜花宝籍碎页", ({ "book"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "张");
        	set("no_split", 1);
        	set("long","王怜花所著，记载着武林中人梦寐以求的武功心法，归隐
前将此书交给林诗音，希望林的意中人李寻欢他日为自己
找一个天资高、心术正的衣钵传人。后李寻欢上官金虹决
斗之日，此书随龙啸云被杀而从此失传。。。。。这似乎
是其中的一张碎页。\n");
        	set("value", 0);
        	set("desc_ext","无价之宝，能换点什么呢？");
        	set("pfm_r1",1);
    	}
    	::init_item();
}
