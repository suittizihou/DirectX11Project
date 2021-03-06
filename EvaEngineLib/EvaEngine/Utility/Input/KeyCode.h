#pragma once

namespace EvaEngine {

    enum class KeyState {
        Up,
        Down
    };

    enum class KeyCode {
        Escape = 0x01,
        Alpha1 = 0x02,
        Alpha2 = 0x03,
        Alpha3 = 0x04,
        Alpha4 = 0x05,
        Alpha5 = 0x06,
        Alpha6 = 0x07,
        Alpha7 = 0x08,
        Alpha8 = 0x09,
        Alpha9 = 0x0A,
        Alpha0 = 0x0B,
        Minus = 0x0C,
        Equals = 0x0D,
        Back = 0x0E,
        Tab = 0x0F,
        Q = 0x10,
        W = 0x11,
        E = 0x12,
        R = 0x13,
        T = 0x14,
        Y = 0x15,
        U = 0x16,
        I = 0x17,
        O = 0x18,
        P = 0x19,
        Lbracket = 0x1A,
        Rbracket = 0x1B,
        Return = 0x1C,
        Lcontrol = 0x1D,
        A = 0x1E,
        S = 0x1F,
        D = 0x20,
        F = 0x21,
        G = 0x22,
        H = 0x23,
        J = 0x24,
        K = 0x25,
        L = 0x26,
        Semicolon = 0x27,
        Apostrophe = 0x28,
        Grave = 0x29,
        Lshift = 0x2A,
        Backslash = 0x2B,
        Z = 0x2C,
        X = 0x2D,
        C = 0x2E,
        V = 0x2F,
        B = 0x30,
        N = 0x31,
        M = 0x32,
        Comma = 0x33,
        Period = 0x34,
        Slash = 0x35,
        Rshift = 0x36,
        Multiply = 0x37,
        Lmenu = 0x38,
        Space = 0x39,
        Capital = 0x3A,
        F1 = 0x3B,
        F2 = 0x3C,
        F3 = 0x3D,
        F4 = 0x3E,
        F5 = 0x3F,
        F6 = 0x40,
        F7 = 0x41,
        F8 = 0x42,
        F9 = 0x43,
        F10 = 0x44,
        Numlock = 0x45,
        Scroll = 0x46,
        Numpad7 = 0x47,
        Numpad8 = 0x48,
        Numpad9 = 0x49,
        Subtract = 0x4A,
        Numpad4 = 0x4B,
        Numpad5 = 0x4C,
        Numpad6 = 0x4D,
        Add = 0x4E,
        Numpad1 = 0x4F,
        Numpad2 = 0x50,
        Numpad3 = 0x51,
        Numpad0 = 0x52,
        Decimal = 0x53,
        Oem_102 = 0x56,
        F11 = 0x57,
        F12 = 0x58,
        F13 = 0x64,
        F14 = 0x65,
        F15 = 0x66,
        Kana = 0x70,
        Abnt_c1 = 0x73,
        Convert = 0x79,
        Noconvert = 0x7B,
        Yen = 0x7D,
        Abnt_c2 = 0x7E,
        Numpadequals = 0x8D,
        Prevtrack = 0x90,
        At = 0x91,
        Colon = 0x92,
        Underline = 0x93,
        Kanji = 0x94,
        Stop = 0x95,
        Ax = 0x96,
        Unlabeled = 0x97,
        Nexttrack = 0x99,
        Numpadenter = 0x9C,
        Rcontrol = 0x9D,
        Mute = 0xA0,
        Calculator = 0xA1,
        Playpause = 0xA2,
        Mediastop = 0xA4,
        Volumedown = 0xAE,
        Volumeup = 0xB0,
        Webhome = 0xB2,
        Numpadcomma = 0xB3,
        Divide = 0xB5,
        Sysrq = 0xB7,
        Rmenu = 0xB8,
        Pause = 0xC5,
        Home = 0xC7,
        UpArrow = 0xC8,
        Prior = 0xC9,
        LeftArrow = 0xCB,
        RightArrow = 0xCD,
        End = 0xCF,
        DownArrow = 0xD0,
        Next = 0xD1,
        Insert = 0xD2,
        Delete = 0xD3,
        Lwin = 0xDB,
        Rwin = 0xDC,
        Apps = 0xDD,
        Power = 0xDE,
        Sleep = 0xDF,
        Wake = 0xE3,
        Websearch = 0xE5,
        Webfavorites = 0xE6,
        Webrefresh = 0xE7,
        Webstop = 0xE8,
        Webforward = 0xE9,
        Webback = 0xEA,
        Mycomputer = 0xEB,
        Mail = 0xEC,
        Mediaselect = 0xED
    };
}