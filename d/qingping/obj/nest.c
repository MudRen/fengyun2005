// XXDER
inherit ITEM;
void create()
{
   set_name("小鸟窝", ({ "nest" , "小鸟窝", "鸟窝" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "个");
      set("long", "一个用细茅草和小树棍搭成的小鸟窝，里面垫着柔软的羽毛。\n");
      set("value", 1);
   }
}
int is_container() { return 1; }
