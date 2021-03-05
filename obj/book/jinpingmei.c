 inherit ITEM;
void create()
{
        set_name("金瓶梅", ({ "jinpingmei" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                	set("no_split",1);
                set("long",
"                        
      ,;'      ',, ;; ,,,,,,;,  ;;    ,;,
     ,;';,     ,;,,;,;,;;   ,   ;;   ,;;,,,,,
   ,;'   ';,,   ;; ;;  ;;'';;''';;'',;'    ,
,,';,,,,,,,';;' ;; ;;  ;;, ;;  ;;;,' ;;''';;'
      ;;  ,    ';;';;'';; ';; ,';; ;,;;,;,;;'
  ';'';;'';'    ;; ;;  ;;,,;; ; ;; ;';; ',;;
   ';,;; ,;'    ;; ;;  ;'' ;;   ;;   ;;,,,;;,
 ,,,;,;;;;,,;, ,'  ;'      ';'  ;;   '   ,;'
\n"                );
                set("value", 200000);
                set("no_drop", 1);
                set("no_get", 1);
                set("no_sell", 1);
                set("material", "paper");
                set("desc_ext","ｓｔｕｄｙ");
        }
        ::init_item();
}
void init()
{
  if(this_player()==environment())
  add_action("do_study","study");
}
int do_study(string arg)
{
        object me,ob;
        int sena;
        int cps;
        string book;
        me = this_player();
        cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("指令格式：study <书> <神数量>\n");
        if( (string)book != "jinpingmei")
                return notify_fail("你要读什麽？\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("你要读什麽？\n");
       switch( random(3) ) {
                case 0:
        message("vision", me->name() + "正欣喜若狂地翻读着" + ob->name()
                + "。\n", environment(me), me);
                        break;
                case 1:
        message("vision", me->name() + "翻了一页" + ob->name()
                + "，抬起头用色迷迷眼神上上下下的打量着你。\n", environment(me), me);
                        break;
                case 2:
        message("vision", me->name() + "飞快地翻读着" + ob->name()
                + "，＂啪＂的一声，一滴口水滴在书上。\n", environment(me), me);
                        break;
        }
                write("
                    天下第一风流小说 
                      《金瓶梅》 
\n");
        if( cps >20 )
        {       write("你越读越想读．．．\n");
                return 1;
        }
        if( cps >10)
        {       write("你感到全身发热，越读越想读．．．\n");
                return 1;
        }
                write("你感到一股热气从丹田直升而起．．．\n");
                message("vision",me->name()+"身子突然抖了一抖,手中的"+ob->name()+"竟然也掉到了地上．．．\n", environment(me), me);
                write("你的身子突然抖了一抖,手中的"+ob->name()+"也掉到了地上．．．\n");
                me->set_skill("incarnation",161);
                me->unconcious();
               
                destruct(ob);
                return 1; 
}       
