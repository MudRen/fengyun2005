inherit ITEM;

void create()
{
   set_name("小猫咪", ({ "little cat" , "cat"}) );
   set_weight(500);
   set_max_encumbrance(1);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "只");
      set("long", "一只小小的，有着黄白花纹的小猫，正懒洋洋地趴在针线篮里打呼噜。\n");
      set("value", 1);
   }
    ::init_item();
}

int is_container() { return 1; }


