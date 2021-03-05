//XXDER
inherit ITEM;
void create()
{
   set_name("白玉瓶", ({ "yu ping", "bottle", "玉瓶" }) );
   set_weight(500);
   set_max_encumbrance(100);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "个");
      set("long", "一个用蓝田玉做成的小瓶子。\n");
      set("value", 0);
   }
    ::init_item();
}

int is_container() { return 1; }
