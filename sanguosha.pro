#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T18:50:34
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sanguosha

TEMPLATE = app
CONFIG -= console
#CONFIG += console
#CONFIG -= app_bundle


HEADERS += \
    Zone.h \
    ValueChangeEvent.h \
    TurnEvent.h \
    Trigger.h \
    PrimitiveMoveEvent.h \
    PrimitiveEvent.h \
    Player.h \
    PhaseEvent.h \
    MoveStruct.h \
    MoveEvent.h \
    Lib.h \
    GamePointer.h \
    Game.h \
    Event.h \
    DiscardEvent.h \
    ConsolePlayer.h \
    ClientPlayer.h \
    CardInfo.h \
    Card.h \
    CardType.h \
    NonEquipCard.h \
    UseStruct.h \
    UseEvent.h \
    Slash.h \
    PreUseStruct.h \
    EventBegin.h \
    EventEnd.h \
    HpReductionEvent.h \
    DamageEvent.h \
    Peach.h \
    RecoverEvent.h \
    CounterCard.h \
    Dodge.h \
    DyingEvent.h \
    DeathEvent.h \
    Cheat.h \
    SkillEffect.h \
    Static.h \
    MoveVisibilityEffect.h \
    RegisterSkillEffect.h \
    RemoveSkillEffect.h \
    EquipCard.h \
    WeaponCard.h \
    CiXiongSword.h \
    TargetStruct.h \
    Dismantle.h \
    Thievery.h \
    Divination.h \
    YieldEvent.h \
    NeedYieldEvent.h \
    CardFilter.h \
    SouthernIntruder.h \
    RandomShot.h \
    Duel.h \
    OffensiveHorse.h \
    DefensiveHorse.h \
    QiLinBow.h \
    Halberd.h \
    Transform.h \
    Spear.h \
    ResolveEvent.h \
    DelayedTrick.h \
    TimeWalk.h \
    JudgeEvent.h \
    Lightning.h \
    Harvest.h \
    Friendship.h \
    CounterEvent.h \
    Axe.h \
    NeedUseEvent.h \
    WeaponGambit.h \
    CrossBow.h \
    IceSword.h \
    RenWangShield.h \
    EightDiagram.h \
    mainwindow.h

SOURCES += \
    Zone.cpp \
    TurnEvent.cpp \
    PrimitiveMoveEvent.cpp \
    PrimitiveEvent.cpp \
    Player.cpp \
    PhaseEvent.cpp \
    MoveStruct.cpp \
    MoveEvent.cpp \
    main.cpp \
    Game.cpp \
    Event.cpp \
    DiscardEvent.cpp \
    ConsolePlayer.cpp \
    ClientPlayer.cpp \
    CardInfo.cpp \
    Card.cpp \
    CardType.cpp \
    NonEquipCard.cpp \
    UseStruct.cpp \
    UseEvent.cpp \
     Slash.cpp \
    PreUseStruct.cpp \
    EventBegin.cpp \
    EventEnd.cpp \
    HpReductionEvent.cpp \
    DamageEvent.cpp \
     Peach.cpp \
    RecoverEvent.cpp \
    CounterCard.cpp \
    Dodge.cpp \
    Exception.cpp \
    DyingEvent.cpp \
    DeathEvent.cpp \
    Cheat.cpp \
    Trigger.cpp \
    SkillEffect.cpp \
    Static.cpp \
    MoveVisibilityEffect.cpp \
    RegisterSkillEffect.cpp \
    RemoveSkillEffect.cpp \
    EquipCard.cpp \
    WeaponCard.cpp \
     CiXiongSword.cpp \
    TargetStruct.cpp \
    StarterDeck.cpp \
     Dismantle.cpp \
     Thievery.cpp \
     Divination.cpp \
    YieldEvent.cpp \
    NeedYieldEvent.cpp \
     SouthernIntruder.cpp \
     RandomShot.cpp \
     Duel.cpp \
     OffensiveHorse.cpp \
     DefensiveHorse.cpp \
     QiLinBow.cpp \
     Halberd.cpp \
    Transform.cpp \
     Spear.cpp \
    ResolveEvent.cpp \
    DelayedTrick.cpp \
     TimeWalk.cpp \
    JudgeEvent.cpp \
     Lightning.cpp \
     Harvest.cpp \
     Friendship.cpp \
    CounterEvent.cpp \
     Axe.cpp \
    NeedUseEvent.cpp \
    WeaponGambit.cpp \
     CrossBow.cpp \
     IceSword.cpp \
     RenWangShield.cpp \
     EightDiagram.cpp \
    mainwindow.cpp


FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
