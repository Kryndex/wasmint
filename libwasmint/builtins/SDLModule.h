/*
 * Copyright 2015 WebAssembly Community Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WASMINT_SDLMODULE_H
#define WASMINT_SDLMODULE_H


#include <Module.h>
#include <iostream>
#include <types/Int32.h>

#ifdef WASMINT_HAS_SDL
#include <SDL.h>
#endif

#include <unordered_map>

namespace wasmint {
    class SDLModule : public wasm_module::Module {

#ifdef WASMINT_HAS_SDL
        int textureIndex = 1;

        int32_t windowWidth_ = 0, windowHeight_ = 0;

        SDL_Renderer* ren = nullptr;
        SDL_Window* window_ = nullptr;

        std::unordered_map<int32_t, SDL_Texture*> textures_;
#endif

        void quit();

        SDLModule();

    public:
        virtual ~SDLModule() {
            quit();
        }

        static wasm_module::Module* create() {
            using namespace wasm_module;

            Module* module = new SDLModule();

            return module;
        }
    };
}

#endif //WASMINT_SDLMODULE_H
