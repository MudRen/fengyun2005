inherit ITEM;

void create()
{
   set_name("针线篮", ({ "basket" , "针线篮", "小篮子"}) );
   set_weight(500);
   set_max_encumbrance(4000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "个");
      set("long", "一个用藤条编成的针线篮，藤条已被磨的发光。 \n");
      set("value", 1);
   }
    ::init_item();
}

int is_container() { return 1; }


