inherit ITEM;

void create()
{
        set_name("《美人出浴图》", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "挂");
                set("long", "一挂描绘粗劣的《美人出浴图》，本是世上低俗之人无聊下流之作。\n");
                set("value", 50000);
        }
        ::init_item();
}


void init()
{
        if(this_player()==environment())
                add_action("do_look","look");
}

int do_look(string arg)
{
    object me,ob;
    me = this_player();
        if (!arg)
                return 0;
        ob = present(arg,me);
        if (!ob)
                return 0;
        if (ob != this_object())
                return 0;

        tell_object(me,"一挂描绘粗劣的《美人出浴图》，本是世上低俗之人无聊下流之作。\n但在风云里偏生有很多人喜欢，因此价格也节节拔高。\n");

        if (me->query("gender") == "女性")
        {
                message("vision", me->name() + "展开一卷" + ob->name() + "，登时羞得满面通红。\n", environment(me), me);
                tell_object(me,"你展开画看了一眼，羞得满面通红，连忙又拢卷起来。\n");
                return 1;
        }
        
   switch( random(3) ) {
                        case 0:
        message("vision", me->name() + "正欣喜若狂地欣赏着" + ob->name()
                        + "。\n", environment(me), me);
                                        break;
                        case 1:
        message("vision", me->name() + "左右看看" + ob->name()
                        + "，抬起头用色迷迷眼神上上下下的打量着你。\n", environment(me), me);
                                        break;
                        case 2:
        message("vision", me->name() + "展开" + ob->name()
                        + "轻抚，＂啪＂的一声，一滴口水滴在画上。\n", environment(me), me);
                                        break;
        }
        write("你感到一股热气从丹田直升而起．．．\n");
        me->unconcious();
        return 1;
}

