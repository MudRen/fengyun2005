inherit ITEM;

void create()
{
        set_name("血衣", ({ "blood cloth", "bloodcloth"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "件");
                set("long", "一件浸满鲜血的衣服，上面用血写了几个触目惊心的大字：
	“大哥，我在狼山，帮我！”
        
        小马．
\n");
	}
        set("value", 0);
        ::init_item();
}

